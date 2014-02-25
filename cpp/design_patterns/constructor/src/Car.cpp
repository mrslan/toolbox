#include <stdio.h>
#include "Car.h"
#include "CarBasic.h"

Car::~Car() {
    printf("%s\n", __func__);
}

Car* Car::GetInstance(CarType type) {

    Engine* engine = NULL;
    Brakes* breaks = NULL;
    Car* car = NULL;

    switch(type) {
    case DUMMY:
        engine = Engine::GetInstance(Engine::DUMMY);
        breaks = Brakes::GetInstance(Brakes::DUMMY);
        car = new CarBasic(engine, breaks);
        break;

    default:
        printf("Invalid car type: %d\n", type);
        break;
    }

    if(engine == NULL || breaks == NULL) {
        printf("Failed to create instance of type %d: car:%p, engine:%p, break:%p\n",
                type,
                car,
                engine,
                breaks);

        return NULL;
    }

    return car;
}
