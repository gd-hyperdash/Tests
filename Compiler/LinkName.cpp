/*
    LinkName.cpp
    Custom link names.
    Compile with:
    clang LinkName.cpp
*/

// "Alias" function declarations

[[link_name("srand")]]
extern "C" void setSeed(unsigned int seed);

[[link_name("rand")]]
extern "C" int getRandomNumber(void);

// Entrypoint

int main()
{
    setSeed(0);
    return getRandomNumber();
}