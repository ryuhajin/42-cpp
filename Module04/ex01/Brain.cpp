#include "Brain.hpp"
#include <iostream>
# include <sstream>

Brain::Brain()
{
	std::cout << "[Constructor] Brain" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		std::stringstream itoS;
		itoS << i;
		ideas[i] = "idea " + itoS.str();
	}
}

Brain::Brain(const Brain& in)
{
	std::cout << "[Copy Constructor] Brain" << std::endl;
	
	for (size_t i = 0; i < 100; i++)
		ideas[i] = in.ideas[i];
}

Brain& Brain::operator= (const Brain& in)
{
	std::cout << "[Copy operator] Brain" << std::endl;
	
	if (this == &in)
		return (*this);
	
	for (int i = 0; i < 100; i++)
    	ideas[i] = in.ideas[i];

	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Destructor] Brain" << std::endl;
}
const std::string& Brain::getIdeas (int i) const
{
	return (ideas[i]);
}

void Brain::setIdeas (const std::string& idea, int i)
{
	ideas[i] = idea;
}
