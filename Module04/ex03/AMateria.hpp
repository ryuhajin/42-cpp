#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class AMateria // : public ParentClass
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& in);
	AMateria& operator=(const AMateria& in);
	~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
