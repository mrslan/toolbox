#include "Engine.h"
#include "Breaks.h"

class ICar
{
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual ~ICar() = 0;

    enum CarType {
        DUMMY,
    };

    static ICar* GetInstance(CarType type);

    static void RunSample();
};

class Car: public ICar
{
public:
    Car(IEngine* engine, IBrakes* breaks);
    ~Car();

    void Start();
    void Stop();

private:
    IEngine* mEngine;
    IBrakes* mBreaks;
};
