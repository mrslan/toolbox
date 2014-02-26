package contructor;

public class EngineDummy implements Engine {

  @Override
  public void Start() {
    System.out.println("EngineDummy: Start");
  }

  @Override
  public void Stop() {
    System.out.println("EngineDummy: Stop");
  }

}
