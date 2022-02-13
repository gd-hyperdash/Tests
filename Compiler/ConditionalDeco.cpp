/*
    ConditionalDeco.cpp
    Compile-time conditional decoration.
    Compile with:
    clang -c -emit-llvm -S ConditionalDeco.cpp
*/

#include <stdio.h>

// Global flag

static bool constexpr ENABLE_DECORATOR = true;

// Base function

static void myFunc()
{
    printf("Hello from myFunc()\n");
}

// Decorator definitions

template <bool>
[[decorator(::myFunc)]]
void myDecorator() // enabled
{
    printf("Hello from myDecorator()\n");
}

template <>
void myDecorator<false>(); // disabled

// Explicit instantiation

static auto const& Spec = myDecorator<ENABLE_DECORATOR>;