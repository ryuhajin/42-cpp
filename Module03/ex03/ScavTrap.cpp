#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	:ClapTrap()
{
	hit_Point = 100;
	energy_Point = 50;
	attack_Damage = 20;

	std::cout << '\n';
	std::cout << "[Constructor] ScavTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const std::string & in_name)
	:ClapTrap(in_name)
{
	hit_Point = 100;
	energy_Point = 50;
	attack_Damage = 20;

	std::cout << '\n';
	std::cout << "[Constructor] ScavTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& in)
	:ClapTrap(in)
{
	std::cout << '\n';
	std::cout << "[Copy Constructor] ScavTrap" << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& in)
{
	std::cout << "[Operator] ScavTrap Copy assignment called." << std::endl;

	if (this == &in)
		return (*this);

	ClapTrap::operator=(in);
	
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << '\n';
	std::cout << "[Destructor] ScavTrap : " << name << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_Point == 0)
	{	
		std::cout << "ScavTrap " << name <<
		" [hit point]: 0. The attack fails." << std::endl;
		return ;
	}
	else if (energy_Point == 0)
	{
		std::cout << "ScavTrap " << name <<
		" [energy point]: 0. The attack fails." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << name <<
	" attacks " <<  target << " causing " << attack_Damage
	<< " points of damage!" << std::endl;

	energy_Point--;
}

void ScavTrap::guardGate(void)
{
	if (hit_Point == 0)
	{	
		std::cout << "ScavTrap " << name <<
		" [hit point]: 0. The guardGate fails." << std::endl;
		return ;
	}
	else if (energy_Point == 0)
	{
		std::cout << "ScavTrap " << name <<
		" [energy point]: 0. The guardGate fails." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << name <<
	" is now in Gate keeper mode." << std::endl;

	energy_Point--;
}
