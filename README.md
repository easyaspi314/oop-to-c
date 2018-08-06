# OOP in C
Showing how object-oriented languages truly work by showing equivalent C.

C is the most powerful language. It is capable of doing
virtually *anything*…except you usually have to do it manually.

That is why object-oriented languages like C++, Java, and ObjC
were created, to make the equivalent code easier.

The Lesson1 and Lesson2 files show basic object-oriented
source files in C++, Java, and Objective-C (more languages soon,
PRs welcome), and how they work out manually in C.

The C++ code compiles almost literally to the C source, but
the others use calls to the JDK or `objc_msgSend` and are just
functionally equivalent.

Verbose comments have been added.

# Differences between C

### General

Objects don't exist. They are simulated with structs, which
hold data members in a group.

Member functions don't exist. They are simulated by passing
a pointer to the struct itself as a parameter.

Constructors and destructors don't exist.

`static` has an entirely different meaning.

Partial encapsulation doesn't exist. Data structs can either
be fully opaque or fully transparent. `static` can emulate 
private functions.

C lacks exceptions. Generally, `errno` or return codes are
used instead.

C does not allow overloading or namespaces. Every symbol
must have a unique name, with only one specified declaration.

Memory management is mostly manual.

### C++

RAII, where all objects you declare are initialized and freed
when you are done, does not exist. The following is undefined
behavior (something that you are not supposed to do and is
"anything goes" for the compiler):

```c
int main(void)
{
    int i;
    return i;
}
```

While GCC will usually initialize things to 0, Clang will
not, and upon running this with optimizations, you will
get a random number or argc, depending on the CPU.

No templates or operator overloading.

No STL. C equivalent functions are much different.

Pass-by-reference is a little different:
```cpp
void ChangeValue(int &x)
{
    x = 4;
}
int x:
ChangeValue(x);
```
becomes
```c
void ChangeValue(int *x)
{
    *x = 4;
}
int x;
ChangeValue(&x);
```
Pass-by-move (`int &&x`) is not supported.

The C Standard Library functions (c[name]) are used
differently than idiomatic C++:
```cpp
#include <cstdio>
std::puts("Hai");
```
becomes
```c
#include <stdio.h>
puts("Hai");
```

### Java

**Read up on pointers.** Trying to learn C without understanding
pointers first is a bad idea.

Also, arrays do not have a `.length`.

C also lacks a garbage collector, you need to keep track of
your memory.

### ObjC

Syntax is C-style, using the same syntax as `NSLog`,
`CFRelease`, and any C functions. Box syntax does not exist.

…


# License

All of these source files are released under the MIT license,
see LICENSE.
