package contructor;

public class EngineDummy implements Engine {

  private Logger logger;

  public EngineDummy(Logger logger) {
    this.logger = logger;
    // TODO Auto-generated constructor stub
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
