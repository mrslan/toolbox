#include <iostream>
#include <pthread.h>
#include <vector>

class DataChunk {
public:
    DataChunk(int* data, int size):
        mData(data),
        mSize(size)
    {
    }

    int GetSize() const {
        return mSize;
    }

    int operator[](int idx) {
        if(idx >= mSize) {
            //FIXME DO SOMETHING
            return 0;
        }
        return mData[idx];
    }

private:
    int *mData;
    int mSize;
};

class DataSource {
    static const int DATA_SIZE = 1000;
    static const int NUM_CHUNKS = 100;
    static const int CHUNK_SIZE = DATA_SIZE/NUM_CHUNKS;
public:
    DataSource():
        mData(new int[DATA_SIZE]),
        mCurrentChunk(0)
    {
        pthread_mutex_init(&mMutex, NULL);
        for(int i = 0; i < DATA_SIZE; i++) mData[i] = 1;
    }

    DataChunk GetDataChunk() {
        //TODO refine this function.
        pthread_mutex_lock(&mMutex);
        mCurrentChunk += CHUNK_SIZE;
        if(mCurrentChunk > DATA_SIZE) {
            pthread_mutex_unlock(&mMutex);
            return DataChunk(NULL,0);
        }

        //TODO add DataChunk type to handle border condition
        int remainingData = DATA_SIZE - mCurrentChunk + 1;
        int chunkSize = (remainingData >= CHUNK_SIZE) ? CHUNK_SIZE: remainingData;

        int startPos = mCurrentChunk - CHUNK_SIZE;
        pthread_mutex_unlock(&mMutex);

        return DataChunk(&mData[startPos], chunkSize);
    }

    virtual ~DataSource() {
        delete[] mData;
        pthread_mutex_destroy(&mMutex);
    }

private:
    int* mData;
    int mCurrentChunk;
    pthread_mutex_t mMutex;
};

class ResultData {
public:
    ResultData():
        mSum(NULL)
    {
        pthread_mutex_init(&mMutex, NULL);
    }

    int GetResult() const {
        return mSum;
    }

    void AddResult(int sum) {
        pthread_mutex_lock(&mMutex);
        mSum += sum;
        pthread_mutex_unlock(&mMutex);
    }

    virtual ~ResultData() {
        pthread_mutex_destroy(&mMutex);
    }

private:
    int mSum;
    pthread_mutex_t mMutex;
};


class WorkerThread {
    static int sNumWorkers;
    static const int INVALID = -1;
public:
    WorkerThread():
        mThread(NULL),
        mTID(INVALID),
        mDataSource(NULL),
        mResultData(NULL)
    {
    }

    int Run(DataSource* dataSource, ResultData* result) {
        if(NULL == dataSource) {
            printf("No data source was provided\n");
            return -1;
        }
        if(NULL == result) {
            printf("No data source was provided\n");
            return -1;
        }

        mDataSource = dataSource;
        mResultData = result;
        mTID = sNumWorkers++;
        int rc = pthread_create(&mThread, NULL, &WorkerThread::WorkerThreadLoop, this);
        if(rc != 0) {
            mTID = INVALID;
        }

        return rc;
    }

    ~WorkerThread() {
        pthread_join(mThread, NULL);
        sNumWorkers--;
    }

private:
    static void* WorkerThreadLoop(void * workerThread) {

        WorkerThread* thread = static_cast<WorkerThread*>(workerThread);

        int sum = 0;

        unsigned t0 = clock();

        while(true) {
            // Get next task
            DataChunk data = thread->mDataSource->GetDataChunk();
            if(data.GetSize() == 0) break;

            // Execute task
            for(int i = 0; i < data.GetSize(); i++) {
                usleep(1000);
                sum += data[i];
            }
        }

        thread->mResultData->AddResult(sum);
        printf("%s: Thread is done:%d sum:%d time:%lu\n", __func__, thread->mTID, sum, clock() - t0);

        return NULL;
    }

    pthread_t mThread;
    int mTID;
    DataSource* mDataSource;
    ResultData* mResultData;
};

int WorkerThread::sNumWorkers = 0;

int main() {
    // Create thread pool
    printf("Creating thread pool\n");
    int NUM_THREADS = 4;

    DataSource dataSource;
    ResultData result;

    //TODO change to smart pointers
    std::vector<WorkerThread*> threadPool(NUM_THREADS);

    for(std::vector<WorkerThread*>::iterator it = threadPool.begin();
            it != threadPool.end();
            ++it) {
        *it = new WorkerThread();
    }

    unsigned t0 = clock();

    for(std::vector<WorkerThread*>::iterator it = threadPool.begin();
            it != threadPool.end();
            ++it) {
        (*it)->Run(&dataSource, &result);
    }

    printf("Exiting the program\n");
    for(std::vector<WorkerThread*>::iterator it = threadPool.begin();
            it != threadPool.end();
            ++it) {
        delete(*it);
    }
    unsigned t1 = clock() - t0;

    printf("Exec time(%d), Final result: %d\n", t1, result.GetResult());

}
