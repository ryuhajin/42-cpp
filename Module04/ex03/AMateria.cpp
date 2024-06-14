#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(void)
	:type("default")
{
	std::cout << "[Constructor] AMateria : " << type << std::endl;
}

AMateria::AMateria(std::string const & type)
	:type(type)
{
	std::cout << "[Constructor] AMateria : " << type << std::endl;
}

AMateria::AMateria(const AMateria& in)
	:type(in.type)
{
	std::cout << "[Copy Constructor] AMateria : " << type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& in)
{
	std::cout << "[Copy operator] AMateria : " << type << std::endl;

	if (this == &in)
		return (*this);
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "[Destructor] AMateria : " << type << std::endl;
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
