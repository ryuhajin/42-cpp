#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& rhs);
	Ice& operator=(const Ice& rhs);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif