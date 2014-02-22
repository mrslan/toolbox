#include <stdio.h>
#include <memory>
#include "Car.h"

Car::Car(IEngine* engine, IBrakes* breaks):
        mEngine(engine),
        mBreaks(breaks)
{}

Car::~Car()
{
    delete mEngine;
    mEngine = NULL;

    delete mBreaks;
    mBreaks = NULL;
}

void Car::Start() {
    printf("%s: Staring car\n", __func__);
    mEngine->Start();
    mBreaks->Release();
}

void Car::Stop() {
    printf("%s: Stopping car\n", __func__);
    mBreaks->Apply();
    mEngine->ShutDown();
}

ICar::~ICar() {
    printf("%s\n", __func__);
}

ICar* ICar::GetInstance(CarType type) {

    IEngine* engine = NULL;
    IBrakes* breaks = NULL;

    switch(type) {
    case DUMMY:
        engine = IEngine::GetInstance(IEngine::DUMMY);
        breaks = IBrakes::GetInstance(IBrakes::DUMMY);
        break;

    default:
        printf("Invalid car type: %d\n", type);
        break;
    }

    if(engine == NULL || breaks == NULL) {
        printf("Failed to create instance of type %d: engine:%p, break:%p\n",
                type,
                engine,
                breaks);

        return NULL;
    }

    return new Car(engine, breaks);
}

void ICar::RunSample() {
    std::auto_ptr<ICar> car(ICar::GetInstance(ICar::DUMMY));
    car->Start();
    car->Stop();
}
