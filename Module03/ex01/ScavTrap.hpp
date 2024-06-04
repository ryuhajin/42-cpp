# ifndef SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(const std::string & in_name);
	~ScavTrap();

	void guardGate();
};

#endif
