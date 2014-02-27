package contructor;

public final class EngineBuilder {
  public enum EngineType {
    DUMMY_WITH_CONSOLE_LOGGER,
  }

  public static Engine GetInstance(EngineType type) {
    
    Engine engine = null;
    Logger logger = null;
    
    switch(type) {
    case DUMMY_WITH_CONSOLE_LOGGER:
      logger = LoggerConsole.GetInstance();
      engine = EngineDummy.GetInstance(logger);
      break;
      
      default:
        break;
    }

    return engine;
  }
}
