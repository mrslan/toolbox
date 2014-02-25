#include <memory>
#include "Engine.h"

void Engine::RunSample() {
    std::auto_ptr<Engine> engine(Engine::GetInstance(Engine::DUMMY));
    engine->Start();
    engine->ShutDown();
}
