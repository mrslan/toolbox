package samples;

import contructor.Breaks;
import contructor.BreaksBuilder;
import contructor.BreaksBuilder.BreaksType;

public final class BreaksSample {

  public static void main(String[] args) {
    Breaks breaks = BreaksBuilder.GetInstance(BreaksType.DUMMY);
    breaks.Apply();
    breaks.Release();
  }

}
