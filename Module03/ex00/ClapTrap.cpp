#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string& in_name)
	:name(in_name), hit_Point(10), energy_Point(10), attack_Damage(0)
{
	 std::cout << "[Constructor] ClapTrap" << '\n';
	 std::cout << "name : " << name << '\n';
	 std::cout << "hit Point : " << hit_Point << '\n';
	 std::cout << "energy Point : " << energy_Point << '\n';
	 std::cout << "attack Damage : " << attack_Damage << '\n';
	 std::cout << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[Destructor] ClapTrap : " << name << std::endl;
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
	"attacks " <<  target << "causing " << attack_Damage
	<< "points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
