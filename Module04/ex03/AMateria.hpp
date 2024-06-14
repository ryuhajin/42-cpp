#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& in);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& in);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
private:
	AMateria();
};

#endif
