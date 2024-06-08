#include "FragTrap.hpp"
#include <iostream>
#include <string>

int main()
{
	FragTrap sena("Sena");
	FragTrap teemo("teemo");
	FragTrap lulu("lulu");

	//hit point check
	teemo.takeDamage(5);
	teemo.takeDamage(5);
	teemo.takeDamage(90);
	teemo.attack("lulu");
	teemo.beRepaired(100);

	std::cout << '\n' << std::endl;
	
	//energy point check
	for (size_t i = 0; i < 101; i++)
	{
		sena.attack("Lucian");
	}
	sena.beRepaired(100);

	std::cout << '\n' << std::endl;

	//Frag trap skill
	lulu.highFivesGuys();
	lulu.attack("sena");
	sena.takeDamage(20);
	lulu.beRepaired(100);

	return (0);
}