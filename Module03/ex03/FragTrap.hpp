#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& in);
	FragTrap(const std::string & in_name);
	~FragTrap();

	FragTrap& operator = (const FragTrap& in);
	void highFivesGuys(void);
};
