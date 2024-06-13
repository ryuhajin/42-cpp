#include "bottom.hpp"
#include <iostream>
#include <string>

Bottom::Bottom()
{
	for (size_t i = 0; i < 3; i++)
	{
		bottom[i] = NULL;
	}
}

Bottom::Bottom(const Bottom& in)
{

}

Bottom& Bottom::operator=(const Bottom& in)
{

}

Bottom::~Bottom()
{

}

void	Bottom::ontheBottom(AMateria* materia)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (bottom[i] == NULL)
		{
			bottom[i] = materia;
			return ;
		} 	
	}

	std::cout << "bottom is full." << std::endl;
	return ;
}
