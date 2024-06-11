#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	:WrongAnimal("WrongCat")
{
	std::cout << "[Constructor] WrongCat" << '\n' << std::endl;
}

WrongCat::WrongCat(const WrongCat& in)
	:WrongAnimal(in)
{
	std::cout << "[Copy Constructor] WrongCat" << '\n' << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& in)
{
	std::cout << "[Copy operator] WrongCat" << '\n' << std::endl;

	if (this == &in)
		return (*this);

	WrongAnimal::operator=(in);

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[Destructor] WrongCat" << '\n' << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << type << ": "<< "😼 meow~~ 😼" << std::endl;
}
