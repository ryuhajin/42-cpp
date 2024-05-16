#include "HumanB.h"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string &input)
{
	name = input;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon *type)
{
	weapon = type;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}
