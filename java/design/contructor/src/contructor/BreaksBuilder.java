package contructor;

public final class BreaksBuilder {
  public enum BreaksType {
    DUMMY,
  }
  
  public static Breaks GetInstance(BreaksType type) {
    
    Breaks breaks = null;
    
    switch (type) {
    case DUMMY:
      breaks = new BreaksDummy();
      break;

    default:
      break;
    }
    
    return breaks;
  }
}
