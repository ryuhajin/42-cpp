#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria()
	:type("")
{
	std::cout << "[Constructor] AMateria : " << type << std::endl;
}

AMateria::AMateria(const AMateria& in)
{
	std::cout << "[Copy Constructor] AMateria" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& in)
{
	std::cout << "[Copy Operator] AMateria" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[Destructor] AMateria : " << type << std::endl;
}
