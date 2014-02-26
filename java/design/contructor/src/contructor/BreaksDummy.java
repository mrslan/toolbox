package contructor;

public class BreaksDummy implements Breaks {

  @Override
  public void Apply() {
    System.out.println("BreaksDummy: Apply");
  }

  @Override
  public void Release() {
    System.out.println("BreaksDummy: Release");
  }

}
