#include "Character.hpp"
#include <iostream>
#include <string>


Character::Character()
	:name("Default")
{
	std::cout << "[Constructor] Character" << '\n'
	<< "name : " << name << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		slot[i] = NULL;
	}
}

Character::Character(const std::string & in_name)
	:name(in_name)
{
	std::cout << "[Constructor] Character" << '\n'
	<< "name : " << name << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		slot[i] = NULL;
	}
}

Character::Character(const Character& in)
	:name(in.name)
{
	std::cout << "[Copy Constructor] Character : " << name << std::endl;
	
	for (size_t i = 0; i < 4; i++)
	{
		if (in.slot[i] != NULL)
			slot[i] = in.slot[i]->clone();
	}
}

Character& Character::operator=(const Character& in)
{
	std::cout << "[Copy operator=] Character : " << name << std::endl;
	
	if (this == &in)
		return (*this);
	
	name = in.name;

	for (size_t i = 0; i < 4; i++)
		delete slot[i];
	
	for (size_t i = 0; i < 4; i++)
	{
		if (in.slot[i] != NULL)
			slot[i] = in.slot[i]->clone();
	}	
	return (*this);
}

Character::~Character()
{
	std::cout << "[Destructor] Character : " << name << std::endl;
	
	for (size_t i = 0; i < 4; i++)
	{
		delete slot[i];
	}
}

std::string const & Character::getName(void) const
{
	return (name);
}

void	Character::equip (AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Unknown Material. cannot be equipped." << std::endl;
		return ;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{	
			slot[i] = m;
			std::cout << '\n' << "#Success equip slot[" << i << "] : " << m->getType() << ".\n" << std::endl;
			return ;
		}
	}

	std::cout << "inventory slot if full. Cannot be equipped." << std::endl;
	return ;
}

void	Character::unequip (int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Not a valid index." << std::endl;
		return ;
	}

	if (slot[idx] == NULL)
	{
		std::cout << "The slot [" << idx << "] is empty." << std::endl;
		return ;
	}

	std::cout << "The slot [" << idx << "] unequip" << std::endl;

	slot[idx] = NULL;

	return;
}

void	Character::use (int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Not a valid index." << std::endl;
		return ;
	}

	if (slot[idx] == NULL)
	{
		std::cout << "The slot [" << idx << "] is empty." << std::endl;
		return ;
	}

	slot[idx]->use(target);
	return;
}
