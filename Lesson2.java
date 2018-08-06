import Lesson2Base;

public class Lesson2 extends Lesson2Base {
    public int b;

    public Lesson2() {
        System.out.println("Lesson2 ctor");
    }

    @Override
    public void DoSomething() {
        System.out.println("Lesson2 DoSomething");
    }

    public static void main(String[] args) {
        Lesson2 l2 = new Lesson2();
        l2.DoSomething();

        Lesson2Base l2b = new Lesson2Base();
        l2b.DoSomething();

        exit(0);
    }
}
