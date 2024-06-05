#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap()
	:name("Default"), hit_Point(10), energy_Point(10), attack_Damage(0)
{
	std::cout << '\n';
	std::cout << "[Constructor] ClapTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const std::string& in_name)
	:name(in_name), hit_Point(10), energy_Point(10), attack_Damage(0)
{
	std::cout << '\n';
	std::cout << "[Constructor] ClapTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& in)
	:name(in.name),
	hit_Point(in.hit_Point),
	energy_Point(in.energy_Point),
	attack_Damage(in.attack_Damage)
{
	std::cout << '\n';
	std::cout << "[Copy Constructor] ClapTrap" << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << '\n';
	std::cout << "[Destructor] ClapTrap : " << name << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& in)
{
	std::cout << "[Operator] ClapTrap Copy assignment called." << std::endl;

	if (this == &in)
		return (*this);
	
	name = in.name;
	hit_Point = in.hit_Point;
	energy_Point = in.energy_Point;
	attack_Damage = in.attack_Damage;

	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_Point == 0)
	{	
		std::cout << "ClapTrap " << name <<
		" [hit point]: 0. The attack fails." << std::endl;
		return ;
	}
	else if (energy_Point == 0)
	{
		std::cout << "ClapTrap " << name <<
		" [energy point]: 0. The attack fails." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name <<
	" attacks " <<  target << " causing " << attack_Damage
	<< " points of damage!" << std::endl;

	energy_Point--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_Point > 0)
	{
		hit_Point -= amount;
	
		std::cout << "ClapTrap " << name <<
		" takes " << amount << " damege." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name <<
		" already has 0 hit point." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_Point == 0)
	{	
		std::cout << "ClapTrap " << name <<
		" [hit point]: 0. beRepair fails." << std::endl;
		return ;
	}
	else if (energy_Point == 0)
	{
		std::cout << "ClapTrap " << name <<
		" [energy point]: 0. beRepair fails." << std::endl;
		return ;
	}

	hit_Point += amount;
	energy_Point--;

	std::cout << "ClapTrap " << name <<
	" has regained " << amount << " hit point." << std::endl;
}
