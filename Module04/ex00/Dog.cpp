#include "Dog.hpp"
#include <iostream>


Dog::Dog()
	:Animal("Dog")
{
	std::cout << "[Constructor] Dog" << '\n' << std::endl;
}

Dog::Dog(const std::string& in_string)
	:Animal(in_string)
{
	std::cout << "[Constructor] Dog" << '\n' << std::endl;
}

Dog::Dog(const Dog& in)
	:Animal(in)
{
	std::cout << "[Copy Constructor] Dog" << '\n' << std::endl;
}

Dog& Dog::operator= (const Dog& in)
{
	std::cout << "[Copy operator] Dog" << '\n' << std::endl;

	if (this == &in)
		return (*this);

	Animal::operator=(in);

	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Destructor] Dog" << '\n' << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": "<< "🐶 bark bark!!! 🐶" << std::endl;
}
