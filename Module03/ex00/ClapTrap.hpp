# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string name;
	unsigned int hit_Point;
	unsigned int energy_Point;
	unsigned int attack_Damage;
public:
	ClapTrap(std::string& in_name);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
