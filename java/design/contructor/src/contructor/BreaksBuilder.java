package contructor;

import contructor.LoggerBuilder.LoggerType;

public final class BreaksBuilder {
  public enum BreaksType {
    DUMMY_WITH_CONSOLE_LOGGER,
  }
  
  public static Breaks GetInstance(BreaksType type) {
    
    Breaks breaks = null;
    Logger logger = null;
    
    switch (type) {
    case DUMMY_WITH_CONSOLE_LOGGER:
      logger = LoggerBuilder.GetInstance(LoggerType.CONSOLE);
      breaks = BreaksDummy.GetInstance(logger);
      break;

    default:
      break;
    }
    
    return breaks;
  }
}
