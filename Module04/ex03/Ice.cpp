#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice()
	:AMateria("ice")
{
	std::cout << "[Constructor] Ice" << std::endl;
}

Ice::Ice(const Ice& in)
	:AMateria(in.type)
{
	std::cout << "[Copy Constructor] Ice" << std::endl;
}

Ice& Ice::operator=(const Ice& in)
{
	std::cout << "[Copy operator=] Ice" << std::endl;

	if (this == &in)
		return (*this);

	type = in.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "[Destructor] Ice" << std::endl;
}

AMateria* Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << '\n' << "Ice: * shoots an ice bolt at " << target.getName() << " *\n" << std::endl;
}
