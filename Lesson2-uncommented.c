#include <stdlib.h>
#include <stdio.h>

struct Lesson2Base
{
    void (*DoSomething)(void *);
    int a;
};

struct Lesson2
{
    void (*DoSomething)(void *);
    int a;

    int b;
};

void Lesson2Base_DoSomething(struct Lesson2Base *this)
{
    puts("    Lesson2Base DoSomething called!\n");
}
void Lesson2_DoSomething(struct Lesson2 *this)
{
    puts("    Lesson2 DoSomething called!\n");
}

void Lesson2Base_Ctor(struct Lesson2Base *this)
{
    if (!this->DoSomething)
        this->DoSomething = (void (*)(void *))&Lesson2Base_DoSomething;

    puts("    Lesson2Base ctor called!\n");
}

void Lesson2_Ctor(struct Lesson2 *this)
{
    if (!this->DoSomething)
        this->DoSomething = (void (*)(void *))&Lesson2_DoSomething;

    Lesson2Base_Ctor((struct Lesson2Base *)this);
    puts("    Lesson2 ctor called!\n");
}

int main(void)
{
    puts("Lesson2:");
    struct Lesson2 *l2 = calloc(1, sizeof(struct Lesson2));
    Lesson2_Ctor(l2);

    puts("call DoSomething:");
    l2->DoSomething(l2);

    puts("Cast to base: The same function is called:");
    ((struct Lesson2Base *)l2)->DoSomething(l2);

    free(l2);

    puts("Lesson2Base:");
    struct Lesson2Base *l2b = calloc(1, sizeof(struct Lesson2Base));
    Lesson2Base_Ctor(l2b);

    puts("call DoSomething:");
    l2b->DoSomething(l2b);
    free(l2b);

    return 0;
}
