#include <memory>
#include "Car.h"

void Car::RunSample() {
    std::auto_ptr<Car> car(Car::GetInstance(Car::DUMMY));
    car->Start();
    car->Stop();
}
