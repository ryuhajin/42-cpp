#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* slot[4];
public:
	Character();
	Character(const std::string & in_name);
	Character(const Character& in);
	Character& operator=(const Character& in);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif