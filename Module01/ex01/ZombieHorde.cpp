#include "Zombie.h"
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *arr = new Zombie[N];
	
	for (size_t i = 0; i < N; i++)
	{
		arr[i].get_name() = name;
	}

	return (arr);
}
