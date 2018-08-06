import Lesson2Base;

public class Lesson2 extends Lesson2Base {
    public int b;

    public Lesson2() {
        System.out.println("    Lesson2 ctor called!\n");
    }

    @Override
    public void DoSomething() {
        System.out.println("    Lesson2 DoSomething called!\n");
    }

    public static void main(String[] args) {
        System.out.println("Lesson2:");
        Lesson2 l2 = new Lesson2();
        System.out.println("call DoSomething:");
        l2.DoSomething();
        System.out.println("Cast to base: The same function is called:");
        ((Lesson2Base)l2).DoSomething();

        System.out.println("Lesson2Base:");
        Lesson2Base l2b = new Lesson2Base();
        System.out.println("call DoSomething:");
        l2b.DoSomething();

        exit(0);
    }
}
