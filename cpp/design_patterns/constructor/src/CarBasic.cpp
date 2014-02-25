#include <stdio.h>
#include "CarBasic.h"

CarBasic::CarBasic(Engine* engine, Brakes* breaks):
        mEngine(engine),
        mBreaks(breaks)
{}

CarBasic::~CarBasic()
{
    delete mEngine;
    mEngine = NULL;

    delete mBreaks;
    mBreaks = NULL;
}

void CarBasic::Start() {
    printf("%s: Staring car\n", __func__);
    mEngine->Start();
    mBreaks->Release();
}

void CarBasic::Stop() {
    printf("%s: Stopping car\n", __func__);
    mBreaks->Apply();
    mEngine->ShutDown();
}
