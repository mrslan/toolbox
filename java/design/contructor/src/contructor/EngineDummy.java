package contructor;

public class EngineDummy implements Engine {

  private Logger logger;

  static EngineDummy GetInstance(Logger logger) {
    return new EngineDummy(logger);
  }
  
  private EngineDummy(Logger logger) {
    this.logger = logger;
  }

  @Override
  public void Start() {
    logger.Log("EngineDummy: Start");
  }

  @Override
  public void Stop() {
    logger.Log("EngineDummy: Stop");
  }

}
