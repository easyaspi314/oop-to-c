public class Lesson1 {
    public int x;

    public static void DoSomethingElse() {
        System.out.println("DoSomethingElse");
    }

    public void DoSomething(int value) {
        x = value;
        System.out.println("x = " + x);
        DoSomethingElse();
    }

    public static void main(String[] args) {
        Lesson1 obj = new Lesson1();
        obj.DoSomething();
    }
}

