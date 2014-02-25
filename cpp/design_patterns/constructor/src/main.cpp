#include <stdio.h>
#include "Car.h"

int main()
{
    Engine::RunSample();
    Brakes::RunSample();
    Car::RunSample();

    printf("Execution complete\n");
}

