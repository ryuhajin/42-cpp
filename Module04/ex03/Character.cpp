#include "Character.hpp"
#include <iostream>
#include <string>


Character::Character()
	:name("Default")
{
	std::cout << "[Constructor] Character" << '\n'
	<< "name : " << name << std::endl;
}

Character::Character(const Character& in)
{

}

Character& Character::operator=(const Character& in)
{

}

Character::~Character()
{
	std::cout << "[Destructor] Character : " << name << std::endl;
}

std::string const & Character::getName(void) const
{
	return (name);
}

void	Character::equip (AMateria* m)
{
	if (m->getType() == "ice" || m->getType() == "cure")
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (slot[i] == NULL)
			{	
				slot[i] = m;
				break;
			}
		}
	}
	else
		std::cout << "undefine Materia" << std::endl;

	return;
}

void	Character::unequip (int idx)
{

}

void	Character::use (int idx, ICharacter& target)
{

}
