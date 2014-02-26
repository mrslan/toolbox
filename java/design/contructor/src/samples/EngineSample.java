package samples;

import contructor.Engine;
import contructor.EngineBuilder;
import contructor.EngineBuilder.EngineType;

public final class EngineSample {

  public static void main(String[] args) {
    Engine engine = EngineBuilder.GetInstance(EngineType.DUMMY);
    engine.Start();
    engine.Stop();
  }

}
