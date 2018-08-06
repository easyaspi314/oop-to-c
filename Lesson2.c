#include <stdlib.h>
#include <stdio.h>

/* Avoid unwieldy function pointer syntax. */
typedef void (MemberFn)(void *);

struct Lesson2Base
{
    /*
     * While a more accurate implementation will create
     * a table with all the virtual functions, we will
     * simplify it.
     */
    MemberFn *DoSomething;
    int a;
};

struct Lesson2
{
    /*
     * Lesson2Base declared inline.
     * You will often see this instead:
     * struct Lesson2Base parent;
     * but the important thing is that it is at the top.
     * In data structs, members are read from top to bottom,
     * and if a smaller struct has the same members at the
     * top of a larger struct, a pointer can be cast to the
     * smaller one safely, it will just ignore the extended
     * members.
     */
    MemberFn *DoSomething;
    int a;
    /* Lesson2's (literally) extended members: */
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

/* Now for constructors. */
void Lesson2Base_Ctor(struct Lesson2Base *this)
{
    /*
     * If the pointer to the virtual function hasn't been set,
     * set it.
     *
     * If you are wondering, yes, you can take the address of
     * a function in C.
     */
    if (!this->DoSomething)
        this->DoSomething = (MemberFn *)&Lesson2Base_DoSomething;
    puts("    Lesson2Base ctor called!\n");
}

void Lesson2_Ctor(struct Lesson2 *this)
{
    if (!this->DoSomething)
        this->DoSomething = (MemberFn *)&Lesson2_DoSomething;

    /*
     * Call the parent's ctor, think of it like super.
     * We cast to Lesson2Base which is safe because the top
     * of Lesson2 is the same as Lesson2Base.
     */
    Lesson2Base_Ctor((struct Lesson2Base *)this);
    puts("    Lesson2 ctor called!\n");
}

int main()
{
    puts("Lesson2:");
    /*
     * We use calloc to make sure everything is set to 0.
     * I'm not gonna explain it, Google can do it.
     */
    struct Lesson2 *l2 = calloc(1, sizeof(struct Lesson2));
    Lesson2_Ctor(l2);

    /*
     * Since we set the virtual function in the constructors,
     * and it is a member of the struct, we call it like so,
     * note that we still need the struct as a parameter.
     */
    puts("call DoSomething:");
    l2->DoSomething(l2);

    /*
     * Even when you cast to the base class, you get the same
     * result:
     */
    puts("Cast to base: The same function is called:");
    ((struct Lesson2Base *)l2)->DoSomething(l2);

    free(l2);

    /* The same as above but with the base class */
    puts("Lesson2Base:");
    struct Lesson2Base *l2b = calloc(1, sizeof(struct Lesson2Base));
    Lesson2Base_Ctor(l2b);

    puts("call DoSomething:");
    l2b->DoSomething(l2b);
    free(l2b);

    return 0;
}
