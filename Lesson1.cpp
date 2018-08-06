#include <iostream>

/*
 * Basic objects in C++
 */

class Lesson1 {
public:
    int x;
    static void DoSomethingElse()
    {
        std::cout << "DoSomethingElse" << std::endl;
    }
    void DoSomething(int value);
};

void Lesson1::DoSomething(int value)
{
    x = value;
    std::cout << "x is equal to " << x << "\n";
    DoSomethingElse();
}

int main()
{
    Lesson1 *obj = new Lesson1();
    obj->DoSomething(4);
    delete obj;
}
