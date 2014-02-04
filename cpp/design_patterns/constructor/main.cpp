#include <stdio.h>
#include <memory>

using namespace std;

class ICar
{
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual ~ICar() throw() {
        printf("%s\n", __func__);
    }
};

class IEngine
{
public:
    virtual void Start() = 0;
    virtual void ShutDown() = 0;
    virtual ~IEngine() {
        printf("%s\n", __func__);
    }
};

class DummyEngine: public IEngine
{
public:
    void Start() {
        printf("%s: Starting Engine\n", __func__);
    }

    void ShutDown() {
        printf("%s: Stopping Engine\n", __func__);
    }
};

class IBrakes
{
public:
    virtual void Apply() = 0;
    virtual void Release() = 0;
    virtual ~IBrakes() {
        printf("%s\n", __func__);
    }
};

class DummyBreaks: public IBrakes
{
public:
    void Apply() {
        printf("%s: Applying breaks\n", __func__);
    }

    void Release() {
        printf("%s: Release breaks\n", __func__);
    }
};

class CarParameters
{
public:
    CarParameters():
        mEngine(0),
        mBreaks(0)
    {
    }

    void SetEngine(IEngine* engine) {
        mEngine = engine;
    }

    void SetBreaks(IBrakes* breaks) {
        mBreaks = breaks;
    }

    IEngine* GetEngine() {
        return mEngine;
    }

    IBrakes* GetBreaks() {
        return mBreaks;
    }

private:
    IEngine* mEngine;
    IBrakes* mBreaks;
};

class Car: public ICar
{
public:
    Car(IEngine* engine, IBrakes* breaks):
                    mEngine(engine),
                    mBreaks(breaks)
                    {}

    void Start() {
        printf("%s: Staring car\n", __func__);
        mEngine->Start();
        mBreaks->Release();
    }

    void Stop() {
        printf("%s: Stopping car\n", __func__);
        mBreaks->Apply();
        mEngine->ShutDown();
    }

private:
    IEngine* mEngine;
    IBrakes* mBreaks;
};

class CarBuilder
{
public:
    static ICar* BuildCar(CarParameters& params) throw() {
        if(0 == params.GetEngine() || 0 == params.GetBreaks()) return 0;

        return new Car(params.GetEngine(), params.GetBreaks());
    }
};

void TestEngine()
{
    std::auto_ptr<IEngine> engine(new DummyEngine());
    engine->Start();
    engine->ShutDown();
}

void TestBreaks()
{
    std::auto_ptr<IBrakes> breaks(new DummyBreaks());
    breaks->Apply();
    breaks->Release();
}

void UnitTests()
{
    printf("%s: E\n", __func__);
    TestEngine();
    TestBreaks();
    printf("%s: X\n", __func__);
}

int main()
{
    UnitTests();

    std::auto_ptr<IEngine> engine(new DummyEngine());
    std::auto_ptr<IBrakes> breaks(new DummyBreaks());

    CarParameters params;
    params.SetBreaks(breaks.get());
    params.SetEngine(engine.get());

    std::auto_ptr<ICar> car(CarBuilder::BuildCar(params));
    car->Start();
    car->Stop();

    printf("Execution complete\n");
}

