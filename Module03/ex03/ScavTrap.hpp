# ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& in);
	ScavTrap(const std::string & in_name);
	~ScavTrap();

	ScavTrap& operator = (const ScavTrap& in);

	void	attack(const std::string& target);
	void	guardGate();
};

#endif
