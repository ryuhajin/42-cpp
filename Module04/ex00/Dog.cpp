#include "Dog.hpp"
#include <iostream>


Dog::Dog()
	:Animal("Dog")
{
	std::cout << "[Constructor] Dog" << std::endl;
}

Dog::Dog(const Dog& in)
	:Animal(in)
{
	std::cout << "[Copy Constructor] Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& in)
{
	std::cout << "[Copy operator] Dog" << std::endl;

	if (this == &in)
		return (*this);

	Animal::operator=(in);

	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Destructor] Dog" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": "<< "🐶 bark bark!!! 🐶" << std::endl;
}
