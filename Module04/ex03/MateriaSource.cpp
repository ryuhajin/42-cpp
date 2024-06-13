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
	for (size_t i = 0; i < 4; i++)
	{
		if (in.materia_slot[i] != NULL)
			materia_slot[i] = in.materia_slot[i]->clone();
	}


}

MateriaSource& MateriaSource::operator=(const MateriaSource& in)
{
	std::cout << "[Copy operator=] MateriaSource" << std::endl;

	if (this == &in)
		return (*this);

	for (size_t i = 0; i < 4; i++)
		delete materia_slot[i];
	
	for (size_t i = 0; i < 4; i++)
	{
		if (in.materia_slot[i] != NULL)
			materia_slot[i] = in.materia_slot[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "[Destructor] MateriaSource" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		delete materia_slot[i];
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia_slot[3] != NULL)
	{
		std::cout << "materia slot is full. learnMateria fail." << std::endl;
		return ;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (materia_slot[i] == NULL)
		{
			if (materia->getType() == "ice" || materia->getType() == "cure")
			{
				std::cout << '\n' << "#learn Materia : slot[" << i << "] materia type: " << materia->getType() << '\n' << std::endl;	
				materia_slot[i] = materia;
				return ;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (materia_slot[i] != NULL)
		{
			if (materia_slot[i]->getType() == type)
				return (materia_slot[i]->clone());
		}
	}

	std::cout << "Unknown Material. cannot be created. error." << std::endl;
	return (NULL);
}
