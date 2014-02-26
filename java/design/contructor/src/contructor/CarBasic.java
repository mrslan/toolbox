package contructor;

public class CarBasic implements Car {

  private Engine engine;
  private Breaks breaks;
  private Logger logger;

  CarBasic(Engine engine, Breaks breaks, Logger logger) {
    this.engine = engine;
    this.breaks = breaks;
    this.logger = logger;
    
  }
  
  @Override
  public void Start() {
    logger.Log("Starting car");
    engine.Start();
    breaks.Release();
  }

  @Override
  public void Stop() {
    logger.Log("Stopping car");
    breaks.Apply();
    engine.Stop();
    
  }

}
