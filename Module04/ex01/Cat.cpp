#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	:Animal("Cat"), brain(new Brain())
{
	std::cout << "[Constructor] Cat" << std::endl;
}

Cat::Cat(const std::string& in_string)
	:Animal(in_string), brain(new Brain())
{
	std::cout << "[Constructor] Cat" << std::endl;
}

Cat::Cat(const Cat& in)
	:Animal(in), brain(new Brain(*in.brain))
{
	std::cout << "[Copy Constructor] Cat" << std::endl;
}

Cat& Cat::operator= (const Cat& in)
{
	std::cout << "[Copy operator] Cat" << std::endl;

	if (this == &in)
		return (*this);

	Animal::operator=(in);
	brain = in.brain;

	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Destructor] Cat" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << type << ": "<< "😼 meow~~ 😼" << std::endl;
}

Brain* Cat::getBrain(void)
{
	return (brain);
}

void Cat::setBrain (const std::string& idea, int i)
{
	brain->setIdeas(idea, i);
}
