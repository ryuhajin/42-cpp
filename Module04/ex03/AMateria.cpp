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
	if (getType() == "ice")
		std::cout << "Ice: * shoots an ice bolt at "
		<< target.getName() << "*" << std::endl;
	else
		std::cout << "Cure: * heals " << target.getName()
		<< "’s wounds *" << std::endl;	
}
