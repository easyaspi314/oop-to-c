#include <stdio.h>

class Lesson2Base
{
public:
    int a;
    Lesson2Base()
    {
        puts("    Lesson2Base ctor called!\n");
    }
    virtual void DoSomething()
    {
        puts("    Lesson2Base DoSomething called!\n");
    }
    virtual ~Lesson2Base() = default;
};

class Lesson2 : public Lesson2Base
{
public:
    Lesson2() : Lesson2Base()
    {
        puts("    Lesson2 ctor called!\n");
    }
    int b;
    void DoSomething() override
    {
        puts("    Lesson2 DoSomething called!\n");
    }
};

int main()
{
    puts("Lesson2:");
    Lesson2 *l2 = new Lesson2();
    puts("call DoSomething:");
    l2->DoSomething();
    puts("Cast to base: The same function is called:");
    (reinterpret_cast<Lesson2Base *>(l2))->DoSomething();

    delete l2;
    puts("Lesson2Base:");
    Lesson2Base *l2b = new Lesson2Base();
    puts("call DoSomething:");
    l2b->DoSomething();

    delete l2b;

    return 0;
}
