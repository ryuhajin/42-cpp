#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	:Animal("Dog"), brain(new Brain())
{
	std::cout << "[Constructor] Dog" << std::endl;
}

Dog::Dog(const std::string& in_string)
	:Animal(in_string), brain(new Brain())
{
	std::cout << "[Constructor] Dog" << std::endl;
}

Dog::Dog(const Dog& in)
	:Animal(in), brain(new Brain(*in.brain))
{
	std::cout << "[Copy Constructor] Dog" << std::endl;
}

Dog& Dog::operator= (const Dog& in)
{
	std::cout << "[Copy operator] Dog" << std::endl;

	if (this == &in)
		return (*this);

	Animal::operator=(in);

	Brain* copy_brain = new Brain(*in.brain);
	delete brain;
	
	brain = copy_brain;

	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Destructor] Dog" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": "<< "🐶 bark bark!!! 🐶" << std::endl;
}
