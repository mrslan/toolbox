#pragma once

#include "Engine.h"
#include "Breaks.h"

class Car
{
public:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual ~Car() = 0;

    enum CarType {
        DUMMY,
    };

    static Car* GetInstance(CarType type);

    static void RunSample();
};
