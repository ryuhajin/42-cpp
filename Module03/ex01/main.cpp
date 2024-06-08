#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	ScavTrap sena("Sena");
	ScavTrap teemo("teemo");
	ScavTrap lulu("lulu");

	//hit point check
	teemo.takeDamage(5);
	teemo.takeDamage(5);
	teemo.takeDamage(90);
	teemo.attack("Lucian");
	teemo.beRepaired(100);
	teemo.guardGate();

	std::cout << '\n' << std::endl;
	//energy point check
	for (size_t i = 0; i < 51; i++)
	{
		sena.attack("Lucian");
	}
	sena.beRepaired(100);
	sena.guardGate();

	std::cout << '\n' << std::endl;

	//Scav trap skill
	lulu.guardGate();
	lulu.attack("sena");
	sena.takeDamage(20);
	lulu.beRepaired(100);

	return (0);
}
