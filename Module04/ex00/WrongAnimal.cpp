#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

WrongAnimal::WrongAnimal()
	:type("default")
{
	std::cout << "[Constructor] WrongAnimal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& in_type)
	:type(in_type)
{
	std::cout << "[Constructor] WrongAnimal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& in)
	:type(in.type)
{
	std::cout << "[Copy Constructor] WrongAnimal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& in)
{
	std::cout << "[Copy operator] WrongAnimal" << '\n';

	if (this == &in)
		return (*this);

	std::cout << "type : " << type << " -> ";
	
	type = in.type;

	std::cout << "type :" << type << '\n' << std::endl;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[Destructor] WrongAnimal" << '\n';
	std::cout << "type :" << type << '\n' << std::endl;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << type << ": " << "???" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::setType(const std::string& in_type)
{
	type = in_type;
}
