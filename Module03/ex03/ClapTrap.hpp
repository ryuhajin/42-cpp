# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hit_Point;
	unsigned int energy_Point;
	unsigned int attack_Damage;
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap& in);
	ClapTrap(const std::string& in_name);
	~ClapTrap();

	ClapTrap& operator = (const ClapTrap& in);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
