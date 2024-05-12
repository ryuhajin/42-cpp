#include "HumanB.h"
#include <string>

HumanB::HumanB()
{
	name = "undefined";
}

HumanB::HumanB(const std::string &input)
{
	name = input;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon type)
{
	weapon = type;
}

