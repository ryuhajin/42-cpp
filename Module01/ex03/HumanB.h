# ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>

class HumanB
{
private:
	Weapon weapon;
	std::string name;
public:
	HumanB();
	HumanB(const std::string &input);
	~HumanB();

	void	HumanB::setWeapon(Weapon type);
	void	attack(void);
};

#endif
