#include <stdlib.h>
#include <stdio.h>

struct Lesson1
{
    int x;
};

void Lesson1_DoSomethingElse(void)
{
    puts("DoSomethingElse");
}

void Lesson1_DoSomething(struct Lesson1 *this, int value)
{
    this->x = value;

    printf("x is equal to %d\n", this->x);

    Lesson1_DoSomethingElse();
}

int main(void)
{
    struct Lesson1 *obj = malloc(sizeof(struct Lesson1));

    Lesson1_DoSomething(obj, 4);

    free(obj);

    return 0;
}
