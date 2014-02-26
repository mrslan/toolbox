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
      logger = new LoggerConsole();
      break;

    default:
      break;
    }
    
    return logger;
  }
}
