#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource()
{
	std::cout << "[Constructor] MateriaSource" << std::endl;
	
	for (size_t i = 0; i < 4; i++)
	{
		materia_slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& in)
{
	std::cout << "[Copy Constructor] MateriaSource" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& in)
{
	std::cout << "[Copy operator=] MateriaSource" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[Destructor] MateriaSource" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materia_slot[i] == NULL)
		{
			if (materia->getType() == "ice" || materia->getType() == "cure")
			{
				std::cout << "learn Materia : slot[" << i << "] add materia type: " << materia->getType() << std::endl;	
				materia_slot[i] = materia;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materia_slot[i]->getType() == type)
			return (materia_slot[i]->clone());
	}

	std::cout << "Unknown Material. cannot be created. error." << std::endl;
	return (NULL);
}
