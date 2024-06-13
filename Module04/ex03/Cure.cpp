#include "AMateria.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>

Cure::Cure()
	:AMateria("cure")
{
	std::cout << "[Constructor] Cure" << std::endl;
}

Cure::Cure(const Cure& in)
{
	std::cout << "[Copy Constructor] Cure" << std::endl;
}

Cure& Cure::operator=(const Cure& in)
{
	std::cout << "[Copy operator=] Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "[Destructor] Cure" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure());
}

void use(ICharacter& target)
{
	std::cout << "Cure: * heals " << target.getName() << "’s wounds *" << std::endl;	
}
