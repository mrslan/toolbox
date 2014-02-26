package contructor;

public class CarBasic implements Car {

  private Engine engine;
  private Breaks breaks;

  CarBasic(Engine engine, Breaks breaks) {
    this.engine = engine;
    this.breaks = breaks;
    
  }
  
  @Override
  public void Start() {
    System.out.println("Starting car");
    engine.Start();
    breaks.Release();
  }

  @Override
  public void Stop() {
    System.out.println("Stopping car");
    breaks.Apply();
    engine.Stop();
    
  }

}
