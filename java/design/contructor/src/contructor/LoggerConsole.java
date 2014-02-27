package contructor;

public class LoggerConsole implements Logger {
  
  public static LoggerConsole GetInstance() {

    if(logger == null) logger = new LoggerConsole();

    return logger;
  }
  
  @Override
  public void Init() {
  }

  @Override
  public void Log(String message) {
    System.out.println("> " + message);
  }

  @Override
  public void Deinit() {
  }
  
  private LoggerConsole() {};
  
  private static LoggerConsole logger = null;

}
