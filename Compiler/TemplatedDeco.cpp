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
T printTypeName()
{
	printf("Type is: %s\n", typeid(T).name());
}

// Decorator definition

template <typename R>
[[decorator(::printTypeName<R>)]]
R deco()
{
	printf("Hello from decorator!\n");
}

// Explicit instantiation

static auto const& Spec = deco<char>;