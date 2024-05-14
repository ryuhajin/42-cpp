#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string &input, const Weapon &type)
{
	name = input;
	weapon = type;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
