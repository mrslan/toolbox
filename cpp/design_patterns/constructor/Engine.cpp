#include <stdio.h>
#include <memory>
#include "Engine.h"

DummyEngine::DummyEngine() {
}


DummyEngine::~DummyEngine() {
}

void DummyEngine::Start() {
    printf("%s: Starting Engine\n", __func__);
}

void DummyEngine::ShutDown() {
    printf("%s: Stopping Engine\n", __func__);
}

IEngine::~IEngine() {
    printf("%s\n", __func__);
}

IEngine* IEngine::GetInstance(EngineType type) {
    IEngine* engine = NULL;

    switch(type) {
    case DUMMY:
        engine = new DummyEngine();
        break;

    default:
        printf("%s: Invalid type: %d\n", __func__, type);
        break;
    }

    if(engine == NULL) {
        printf("Failed to create instance of type %d: engine:%p\n",
                type,
                engine);

        return NULL;
    }

    return engine;
}

void IEngine::RunSample() {
    std::auto_ptr<IEngine> engine(IEngine::GetInstance(IEngine::DUMMY));
    engine->Start();
    engine->ShutDown();
}
