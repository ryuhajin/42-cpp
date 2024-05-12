# include "Zombie.h"
# include <iostream>
# include <string>

Zombie::Zombie()
{
	name = "undefined";
}

Zombie::Zombie(std::string input)
{
	name = input;
}

Zombie::~Zombie()
{
	std::cout << name << " : " << "Noooo! I don't want to die..." << std::endl;
	std::cout << name << " is dead." << std::endl;
}

std::string&   Zombie::get_name(void)
{
	return (name);
}

void	Zombie::announce(void)
{
	std::cout << get_name() << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
