# OOP in C
Showing how object-oriented languages truly work by showing equivalent C.

C is a very powerful language. It is capable of doing
virtually *anything*…except you usually have to do it yourself. :)

That is why object-oriented languages like C++, Java, Python, Ruby,
and ObjC were created, to make the equivalent code easier.

The Lesson1 and Lesson2 files show basic object-oriented
source files in C++, Java, Ruby, Python, and Objective-C
(more languages soon, PRs welcome), and how they work out manually in C.

The C++ code compiles almost literally to the C source, but
the others use calls to the JDK or `objc_msgSend` and are just
functionally equivalent.

Verbose comments have been added, however, uncommented versions
are also available.

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

### Python and Ruby

The syntax is weird on C if you are used to Python. Everything needs a semicolon,
and indentation is just aesthetic. **Make sure you have braces around your if/while/for
statements:**

```c
if (foo == bar)
    doSomething();
    doSomethingElse();
```

is parsed as this:
```c
if (foo == bar) {
    doSomething();
}
doSomethingElse(); // always executed
```

In Ruby, `end` is basically `}`, and in Python, it is the end of an indentation.

Everything needs a type when first declared:

```c
int x = 0;
void foo(int x, int y) {}
```

Just like Java, it is important to read about pointers.

Strings use double quotes, single letters use single quotes.

Comments are like this:

```c
/*
block
comment
*/
// line comment (a #comment
```

Lines starting with a `#` are for the preprocessor.

// is a comment. Integer division uses a single slash, and float division only
occurs when one type is explicitly float or double.

Structs (C's "classes") need their members declared before. There is no
`self.anything`.

```c
struct Foo {
    int x;
};
```

Formatting strings is a little tricky.

And arrays don't contain a `.length`.

All startup must begin in the `main` function.

Ruby: All function calls and declarations require parentheses.

# License

All of these source files are released under the MIT license,
see LICENSE.
