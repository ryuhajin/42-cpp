# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string name;
	int hit_Point;
	int energy_Point;
	int attack_Damage;
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
