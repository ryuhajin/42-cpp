#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materia_slot[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& in);
	MateriaSource& operator=(const MateriaSource& in);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif