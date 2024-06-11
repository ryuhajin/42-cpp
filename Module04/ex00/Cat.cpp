#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	:Animal("Cat")
{
	std::cout << "[Constructor] Cat" << '\n' << std::endl;
}
Cat::Cat(const std::string& in_string)
	:Animal(in_string)
{
	std::cout << "[Constructor] Cat" << '\n' << std::endl;
}

Cat::Cat(const Cat& in)
	:Animal(in)
{
	std::cout << "[Copy Constructor] Cat" << '\n' << std::endl;
}

Cat& Cat::operator= (const Cat& in)
{
	std::cout << "[Copy operator] Cat" << '\n' << std::endl;

	if (this == &in)
		return (*this);

	Animal::operator=(in);

	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Destructor] Cat" << '\n' << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << type << ": "<< "😼 meow~~ 😼" << std::endl;
}
