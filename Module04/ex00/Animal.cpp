#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal()
	:type("default")
{
	std::cout << "[Constructor] Animal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

Animal::Animal(const std::string& in_type)
	:type(in_type)
{
	std::cout << "[Constructor] Animal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

Animal::Animal(const Animal& in)
	:type(in.type)
{
	std::cout << "[Copy Constructor] Animal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

Animal& Animal::operator=(const Animal& in)
{
	std::cout << "[Copy operator] Animal" << '\n';

	if (this == &in)
		return (*this);

	std::cout << "type : " << type << " -> ";
	
	type = in.type;

	std::cout << "type :" << type << '\n' << std::endl;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Destructor] Animal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << type << ": " << "???" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (type);
}

void	Animal::setType(const std::string& in_type)
{
	type = in_type;
}
