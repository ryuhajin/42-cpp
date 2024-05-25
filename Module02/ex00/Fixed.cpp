#include "Fixed.h"
#include <iostream>

//Constructor, Destructor
Fixed::Fixed()
		:value(0)
{
	std::cout << "[constructor] Default Called" << std::endl;
}

Fixed::Fixed(const Fixed& input)
		:value(input.value)
{
	std::cout << "[Constructor] Copy Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "[Destructor] Called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& input)
{
	std::cout << "Copy assignment = operator called" << std::endl;
	if (this == &input)
		return (*this);

	value = input.value;

	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits : member function called"  << std::endl;

	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "SetRawBits : member function called" << std::endl;
	value = raw;
}
