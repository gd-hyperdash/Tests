/*
    SharedDeco.cpp
    Decorator shared among multiple bases.
    Compile with:
    clang -std=c++17 -c -emit-llvm -S SharedDeco.cpp
*/

#include <stdio.h>

void myFunction1()
{
	printf("Hello from myFunction1()\n");
}

void myFunction2()
{
	printf("Hello from myFunction2()\n");
}

template <auto Fn>
[[decorator(Fn)]]
void sharedDecorator()
{
	printf("Hello from sharedDecorator()\n");
}

static auto const& mySpec1 = sharedDecorator<myFunction1>;
static auto const& mySpec2 = sharedDecorator<myFunction2>;