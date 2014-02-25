#pragma once

class Engine
{
public:
    virtual void Start() = 0;
    virtual void ShutDown() = 0;
    virtual ~Engine() = 0;

    enum EngineType {
        DUMMY,
    };

    static Engine* GetInstance(EngineType type);

    static void RunSample();
};
