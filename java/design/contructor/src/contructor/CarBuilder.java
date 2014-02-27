package contructor;

import contructor.LoggerBuilder.LoggerType;

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
    Logger logger = null;
    
    switch (type) {
    case BASIC:
      engine = EngineBuilder.GetInstance(EngineBuilder.EngineType.DUMMY_WITH_CONSOLE_LOGGER);
      breaks = BreaksBuilder.GetInstance(BreaksBuilder.BreaksType.DUMMY_WITH_CONSOLE_LOGGER);
      logger = LoggerBuilder.GetInstance(LoggerType.CONSOLE);
      
      car = new CarBasic(engine, breaks, logger);
      
      break;
    case BASIC_COMPOSITE:
      car = new CarBasic(
          EngineDummy.GetInstance(
              LoggerConsole.GetInstance()
              ),
          BreaksDummy.GetInstance(
              LoggerConsole.GetInstance()
              ),
          LoggerConsole.GetInstance()
          );
    default:
      break;
    }

    return car;
  }
}
