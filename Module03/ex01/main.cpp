#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	ScavTrap sena("Sena");
	ScavTrap teemo("teemo");
	ScavTrap lulu("lulu");

	ClapTrap lucian("Lucian");

	//hit point check
	teemo.takeDamage(5);
	teemo.takeDamage(5);
	teemo.takeDamage(90);
	teemo.attack("Lucian");
	teemo.beRepaired(100);

	//energy point check
	for (size_t i = 0; i < 51; i++)
	{
		sena.attack("Lucian");
	}
	sena.beRepaired(100);

	//Scav trap skill
	lulu.guardGate();
	lulu.attack("sena");
	sena.takeDamage(20);
	lulu.beRepaired(100);

	//Claptrap guardgate
	// lucian.guardGate();

	return (0);
}
