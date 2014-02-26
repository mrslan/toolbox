package contructor;

public class BreaksDummy implements Breaks {

  private Logger logger;

  public BreaksDummy(Logger logger) {
    this.logger = logger;
    // TODO Auto-generated constructor stub
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
