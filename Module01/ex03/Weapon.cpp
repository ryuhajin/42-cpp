#include "Weapon.h"
#include <string>

Weapon::Weapon()
{
	type = "undefined";
}

Weapon::Weapon(const std::string &weapon)
{
	setType(weapon);
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType()
{
	return(this->type);
}

void Weapon::setType(const std::string &input)
{
	type = input;
}
