# ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>

class HumanA
{
private:
	Weapon weapon;
	std::string name;
public:
	HumanA(const std::string& name, const Weapon &type);
	~HumanA();

	void	attack(void);
};

#endif
