#include <stdio.h>
#include "Car.h"

int main()
{
    IEngine::RunSample();
    IBrakes::RunSample();
    ICar::RunSample();

    printf("Execution complete\n");
}

