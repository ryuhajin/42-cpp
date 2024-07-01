#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
        return new A();
        break;

        case 1:
        return new B();
        break;

        case 2:
        return new C();
        break;
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "identify : A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "identify : B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "identify : C type" << std::endl;
    else
        std::cout << "identify : Unknown type" << std::endl;
}
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "identify : A type" << std::endl;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "identify : B type" << std::endl;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "identify : C type" << std::endl;
    }
    catch (...) {}
}
