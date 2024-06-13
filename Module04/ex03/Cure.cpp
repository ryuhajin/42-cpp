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
	:AMateria(in.type)
{
	std::cout << "[Copy Constructor] Cure" << std::endl;
}

Cure& Cure::operator=(const Cure& in)
{
	std::cout << "[Copy operator=] Cure" << std::endl;

	if (this == &in)
		return (*this);

	type = in.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "[Destructor] Cure" << std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << '\n' << "Cure: * heals " << target.getName() << "’s wounds *\n" << std::endl;	
}
