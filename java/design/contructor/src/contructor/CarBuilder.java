package contructor;

public final class CarBuilder {
  
  public enum CarType {
    BASIC,
    BASIC_COMPOSITE,
  }
  
  /**
   * Create instance using predefine components.
   * @param type
   * @return
   */
  
  static public Car GetInstance(CarType type) {
    Car car = null;
    Engine engine = null;
    Breaks breaks = null;
    
    switch (type) {
    case BASIC:
      engine = EngineBuilder.GetInstance(EngineBuilder.EngineType.DUMMY);
      breaks = BreaksBuilder.GetInstance(BreaksBuilder.BreaksType.DUMMY);
      car = new CarBasic(engine, breaks);
      
      break;
    case BASIC_COMPOSITE:
      car = new CarBasic(
          new EngineDummy(),
          new BreaksDummy()
          );
    default:
      break;
    }

    return car;
  }
}
