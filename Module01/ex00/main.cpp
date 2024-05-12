#include "Zombie.h"
#include <string>

int main(void)
{
	randomChump("Zomgun");
	Zombie *ptr = newZombie("Zomyang");

	(*ptr).announce();

	delete ptr;
	return (0);
}
