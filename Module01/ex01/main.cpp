#include "Zombie.h"

int main(void)
{
	Zombie *ptr = zombieHorde(10, "Zombie");
	
	for (size_t i = 0; i < 10; i++)
	{
		ptr[i].announce();
	}
	
	delete [] ptr;

	return (0);
}
