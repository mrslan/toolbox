public class WorkerThread extends Thread {

  public int mId;

  public WorkerThread(int id) {
    mId = id;
  }

  @Override
  public void run() {
    try {
      // Your processing here
      sleep(100);
      System.out.println("Thread " + mId + " is done");
    } catch (InterruptedException e) {
      // Handle the exception here
    }
  }
}
