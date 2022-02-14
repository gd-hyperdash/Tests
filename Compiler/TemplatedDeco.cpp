/*
    TemplatedDeco.cpp
    Templated decorator instantiation.
    Compile with:
    clang -c -emit-llvm -S TemplatedDeco.cpp
*/

#include <stdio.h>
#include <typeinfo>

// Base function

template <typename T>
void printTypeName()
{
	printf("Type is: %s\n", typeid(T).name());
}

// Decorator definition

template <typename R>
[[decorator(::printTypeName<R>)]]
void deco()
{
	printf("Hello from decorator!\n");
}

// Explicit instantiation

static auto const& Spec = deco<char>;