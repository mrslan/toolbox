#include "Car.h"

class CarBasic: public Car
{
public:
    CarBasic(Engine* engine, Brakes* breaks);
    ~CarBasic();

    void Start();
    void Stop();

private:
    Engine* mEngine;
    Brakes* mBreaks;
};
