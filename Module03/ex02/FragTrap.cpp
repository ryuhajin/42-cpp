#include "FragTrap.hpp"
#include <iostream>

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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " : Want to join the positive high-five?"
	<< std::endl;
}
