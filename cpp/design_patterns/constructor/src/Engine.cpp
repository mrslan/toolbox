#include <stdio.h>
#include "Engine.h"
#include "EngineDummy.h"

Engine::~Engine() {
    printf("%s\n", __func__);
}

Engine* Engine::GetInstance(EngineType type) {
    Engine* engine = NULL;

    switch(type) {
    case DUMMY:
        engine = new EngineDummy();
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
