#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice()
	:AMateria("ice")
{
	std::cout << "[Constructor] Ice" << std::endl;
}

Ice::Ice(const Ice& in)
{
	std::cout << "[Copy Constructor] Ice" << std::endl;
}

Ice& Ice::operator=(const Ice& in)
{
	std::cout << "[Copy operator=] Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "[Destructor] Ice" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice());
}

void use(ICharacter& target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
