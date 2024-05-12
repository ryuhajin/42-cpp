# ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(const std::string &weapon);
	~Weapon();

	const std::string&	getType();
	void				setType(const std::string &ref);
};

#endif