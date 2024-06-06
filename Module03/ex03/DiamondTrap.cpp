#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
	:ClapTrap()
{
	name = "DiamondTrap default";
	hit_Point = 100;
	energy_Point = 50;
	attack_Damage = 30;

	std::cout << '\n';
	std::cout << "[Constructor] DiamondTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const std::string & in_name)
	:ClapTrap(in_name + "_Clap_name"), ScavTrap(), FragTrap()
{
	name = in_name;
	hit_Point = 100;
	energy_Point = 50;
	attack_Damage = 30;

	std::cout << '\n';
	std::cout << "[Constructor] DiamondTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& in)
	:ClapTrap(in), ScavTrap(in), FragTrap(in)
{
	name = in.name;

	std::cout << '\n';
	std::cout << "[Copy Constructor] DiamondTrap" << '\n';
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& in)
{
	std::cout << "[Operator] DiamondTrap Copy assignment called." << std::endl;

	if (this == &in)
		return (*this);

	ClapTrap::operator=(in);

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << '\n';
	std::cout << "[Destructor] DiamondTrap : " << name << std::endl;
	std::cout << "name : " << name << '\n';
	std::cout << "hit Point : " << hit_Point << '\n';
	std::cout << "energy Point : " << energy_Point << '\n';
	std::cout << "attack Damage : " << attack_Damage << '\n';
	std::cout << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] name : " << name << '\n' <<
	"[ClapTrap] name : " << ClapTrap::name << '\n' << std::endl;
}
