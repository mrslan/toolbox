package contructor;

public class BreaksDummy implements Breaks {

  private Logger logger;

  public static BreaksDummy GetInstance(Logger logger) {
    return new BreaksDummy(logger);
  }
  
  private BreaksDummy(Logger logger) {
    this.logger = logger;
  }

  @Override
  public void Apply() {
    logger.Log("BreaksDummy: Apply");
  }

  @Override
  public void Release() {
    logger.Log("BreaksDummy: Release");
  }

}
