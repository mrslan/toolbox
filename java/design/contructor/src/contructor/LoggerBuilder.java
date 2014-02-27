package contructor;

public class LoggerBuilder {
  public enum LoggerType {
    CONSOLE,
    FILE,
  }

  public static Logger GetInstance(LoggerType type) {
    Logger logger = null;
    
    switch (type) {
    case CONSOLE:
      logger = LoggerConsole.GetInstance();
      break;

    default:
      break;
    }
    
    return logger;
  }
}
