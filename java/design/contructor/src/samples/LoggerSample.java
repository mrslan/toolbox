package samples;

import contructor.Logger;
import contructor.LoggerBuilder;
import contructor.LoggerBuilder.LoggerType;

public class LoggerSample {
  public static void main(String[] args) {
    Logger logger = LoggerBuilder.GetInstance(LoggerType.CONSOLE);
    
    logger.Init();
    logger.Log("Hello World");
    logger.Deinit();
  }
}
