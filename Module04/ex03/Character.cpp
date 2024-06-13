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
	std::cout << "[Copy Constructor] Character : " << name << std::endl;
}

Character& Character::operator=(const Character& in)
{
	std::cout << "[Copy operator=] Character : " << name << std::endl;
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
	if (m == NULL)
	{
		std::cout << "Unknown material. Cannot be equipped." << std::endl;
		return ;
	}

	if (m->getType() == "ice" || m->getType() == "cure")
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (slot[i] == NULL)
			{	
				slot[i] = m;
				std::cout << "#Success equip slot[" << i << "] : " << m->getType() << '.' << std::endl;
				return ;
			}
		}
	}

	std::cout << "inventory slot if full. Cannot be equipped." << std::endl;
	return ;
}

void	Character::unequip (int idx)
{
	if (idx <= -1 || idx > 3)
	{
		std::cout << "Not a valid index." << std::endl;
		return ;
	}

	if (slot[idx] == NULL)
	{
		std::cout << "The slot [" << idx << "] is empty." << std::endl;
		return ;
	}

	

}

void	Character::use (int idx, ICharacter& target)
{

}
