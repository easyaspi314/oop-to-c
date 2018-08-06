/*
 * stdlib is the core of C's standard library.
 * It provides malloc, the integer types, and
 * more.
 * If you have used <cstdlib>, it is the same thing but
 * without the std:: namespace.
 */
#include <stdlib.h>
/*
 * stdio.h is your iostream. It has basically everything
 * you need for console and file I/O.
 * The same thing applies for <cstdio>.
 */
#include <stdio.h>

/*
 * In C, there are no classes, there are structs.
 * Note that you have to refer to it as "struct Object"
 * instead of just Object.
 * Structs can only have entries for data. You can't
 * add function declarations in it.
 */
struct Lesson1
{
    int x;
    /*
     * You might think the compiler does this:
     *
     *     void (*DoSomething)(void);
     *
     * but it doesn't. Function pointers allow the
     * obj->DoSomething() syntax, but this takes up memory
     * for each instance, has to be reduntantly initialized
     * to the same thing for each instance, and doesn't have
     * access to the struct itself.
     */
};

/*
 * Instead, the compiler uses external functions, passes
 * the pointer to the struct as 'this', and mangles the name.
 * Static functions like this omit 'this' and const functions
 * pass 'const struct Object *const this', making 'this'
 * unmodifiable.
 *
 * For ObjC, Ruby, and Python, substitute 'this' for 'self'.
 *
 * For simplicity, I use human readable mangling schemes,
 * which is much better than _ZN7Lesson115DoSomethingElseEv.
 */
void Lesson1_DoSomethingElse(void)
{
    /*
     * puts is generally going to be your output. It can
     * put a single string to standard output (a.k.a. stdout),
     * followed by a newline character.
     *
     * Equivalents:
     * std::cout << "DoSomethingElse" << std::endl (or '\n')
     * NSLog(@"DoSomethingElse")
     * System.out.println("DoSomethingElse")
     */
    puts("DoSomethingElse");
}

/*
 * This member function, as you can see, has a 'this' passed
 * to it as the first parameter. This is exactly what G++
 * will do.
 */
void Lesson1_DoSomething(struct Lesson1 *this, int value)
{
    /*
     * C++ and Java automatically add "this->" when you
     * access x.
     */
    this->x = value;
    /*
     * When you are just displaying a string, use puts.
     * It is faster and automatically adds a new line.
     * But we want to display a value that is not a string.
     *
     * NOTE:
     *     "x is equal to " + x
     *         is that string, starting at the xth character.
     *     "x is equal to " << x
     *         is a syntax error.
     *     "x is equal to #{x}" (or similar variants)
     *         doesn't do anything special.
     *     You must unlearn what you have learned, you can't
     *     modify strings that way in C.
     *
     * printf puts formatted output to stdout. Just like
     * iostream, you need to add a new line.
     * Read up on it, its entire use is complicated, but the
     * basics are that it will substitute the values in order
     * using the type you specify.
     *
     * If you are familiar with System.out.printf or NSLog
     * with arguments, it is basically the same thing.
     *
     *     %s = string (char *)
     *     %d = signed integer
     *     %u = unsigned integer
     *     %c = A single character, an int converted from its
     *          ASCII value.
     *     %x = hexadecimal
     *     %f = float
     */
    printf("x is equal to %d\n", this->x);

    /*
     * Static functions are just normal calls.
     */
    Lesson1_DoSomethingElse();
}

int main(void) /* Empty parameter lists use void in the decl. */
{
    /*
     * Ah, malloc. It is like new (or alloc), only stupid.
     * While pokeruby does not use malloc because everything
     * is fixed, malloc is a vital part of C anyways.
     *
     * malloc will reserve x bytes of RAM on the heap, and
     * return a generic pointer (void *) which is automatically
     * casted to any pointer you want.
     *
     * It is most commonly used with sizeof.
     *
     * Note that the sizeof does not reference the pointer,
     * but what the pointer points to.
     *
     * An important thing to realize is that just because you
     * have the memoty reserved, doesn't mean it is initialized.
     * You can buy a plot of land, but you need to build a
     * house.
     */
    struct Lesson1 *obj = malloc(sizeof(struct Lesson1));
    /* We leave out the constructor for now. */

    /*
     * In C, instead of calling obj->DoSomething(), you call
     * DoSomething(obj).
     */
    Lesson1_DoSomething(obj, 4);
    /*
     * free is the opposite of malloc. It releases memory.
     * It is like dumb delete/release.
     * Make sure to free whatever you malloc (Java/Python/C#
     * users, pay attention), because C won't do it for you.
     */
    free(obj);

    return 0;
}
