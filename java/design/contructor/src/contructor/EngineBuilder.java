package contructor;

public final class EngineBuilder {
  public enum EngineType {
    DUMMY,
  }

  public static Engine GetInstance(EngineType type) {
    
    Engine engine = null;
    
    switch(type) {
    case DUMMY:
      engine = new EngineDummy();
      break;
      
      default:
        break;
    }

    return engine;
  }
}
