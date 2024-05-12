# ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	std::string& get_name(void);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
