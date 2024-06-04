#include "ScavTrap.hpp"
#include <iostream>
//기본 생성자 //복사생성자 // 대입연산자 만들기

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
void ScavTrap::guardGate(void) //energy point 소모 되는지 물어보기
{
	std::cout << "ScavTrap " << name <<
	" is now in Gate keeper mode." << std::endl;
}
