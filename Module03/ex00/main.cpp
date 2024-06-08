#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	ClapTrap sena("Sena");
	ClapTrap teemo("teemo");
	ClapTrap lucian("Lucian");

	//hit point check
	teemo.takeDamage(5);
	teemo.takeDamage(100);
	teemo.attack("Lucian");
	teemo.beRepaired(100);

	std::cout << "\n" << std::endl;

	//energy point check
	for (size_t i = 0; i < 11; i++)
	{
		sena.attack("Lucian");
	}
	sena.beRepaired(100);

	std::cout << "\n" << std::endl;

	//repair check
	lucian.beRepaired(100);

	return (0);
}
