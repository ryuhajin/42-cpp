#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	:ClapTrap()
{
	hit_Point = 100;
	energy_Point = 100;
	attack_Damage = 30;

	std::cout << '\n';
	std::cout << "[Constructor] FragTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& in)
	:ClapTrap(in)
{
	std::cout << '\n';
	std::cout << "[Copy Constructor] FragTrap" << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

FragTrap::FragTrap(const std::string & in_name)
	:ClapTrap(in_name)
{
	hit_Point = 100;
	energy_Point = 100;
	attack_Damage = 30;

	std::cout << '\n';
	std::cout << "[Constructor] FragTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << '\n';
	std::cout << "[Destructor] FragTrap : " << name << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& in)
{
	std::cout << "[Operator] FragTrap Copy assignment called." << std::endl;

	if (this == &in)
		return (*this);

	ClapTrap::operator=(in);

	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (hit_Point == 0)
	{	
		std::cout << "FragTrap " << name <<
		" [hit point]: 0. The highFivesGuys fails." << std::endl;
		return ;
	}
	else if (energy_Point == 0)
	{
		std::cout << "FragTrap " << name <<
		" [energy point]: 0. The highFivesGuys fails." << std::endl;
		return ;
	}

	std::cout << "FragTrap " << name << " : Want to join the positive high-five?"
	<< std::endl;

	energy_Point--;
}
