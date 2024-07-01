#include "Base.hpp"
#include <iostream>

int main(void)
{
    Base* base = generate();

	std::cout << "[NULL ptr]" << std::endl;
    identify(NULL);

	std::cout << '\n' << "[identify *]" << std::endl;
    identify(base);

	std::cout << '\n' << "[identify &]" << std::endl;
    identify(*base);

    delete base;
    
    return (0);
}
