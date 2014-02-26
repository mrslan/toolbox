package contructor;

public class LoggerConsole implements Logger {

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

}
