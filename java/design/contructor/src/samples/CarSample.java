package samples;

import contructor.Car;
import contructor.CarBuilder;
import contructor.CarBuilder.CarType;

public final class CarSample {
  public static void main(String[] args) {
    Car car = CarBuilder.GetInstance(CarType.BASIC);
    car.Start();
    car.Stop();
  }
}
