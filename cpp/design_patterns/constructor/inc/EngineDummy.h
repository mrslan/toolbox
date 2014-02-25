#include "Engine.h"

class EngineDummy: public Engine
{
public:
    EngineDummy();
    ~EngineDummy();

    void Start();
    void ShutDown();
};
