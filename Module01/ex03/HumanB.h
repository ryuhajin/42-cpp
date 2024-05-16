# ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(const std::string &input);
	~HumanB();

	void	setWeapon(Weapon *type);
	void	attack(void);
};

#endif
