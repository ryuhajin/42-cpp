#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	DiamondTrap sena("Sena");
	DiamondTrap teemo("teemo");
	DiamondTrap lulu("lulu");

	//hit point check
	teemo.takeDamage(5);
	teemo.takeDamage(5);
	teemo.takeDamage(90);
	teemo.attack("lulu");
	teemo.beRepaired(100);

	std::cout << std::endl;

	teemo.whoAmI();

	std::cout << std::endl;

	//energy point check
	for (size_t i = 0; i < 51; i++)
	{
		sena.attack("Lucian");
	}
	sena.beRepaired(100);

	std::cout << std::endl;

	sena.whoAmI();

	std::cout << std::endl;

	//Diamond trap skill
	
	lulu.highFivesGuys();
	lulu.guardGate();
	lulu.attack("sena");
	sena.takeDamage(20);
	lulu.beRepaired(100);
	
	std::cout << '\n' << std::endl;
	
	lulu.whoAmI();

	return (0);
}
