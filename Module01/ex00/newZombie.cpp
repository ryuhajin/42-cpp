#include "Zombie.h"

Zombie* newZombie(std::string name)
{
	Zombie *ptr = new Zombie(name);
	return (ptr);
}
