#include "Fixed.h"
#include <iostream>
#include <cmath>

//Constructor, Destructor
Fixed::Fixed()
		:value(0)
{
	std::cout << "-> Default Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed& input)
		:value(input.value)
{
	std::cout << "-> Copy constructor Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "-> Destructor Called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "-> Int Constructor Called" << std::endl;
	value = input << fractional_bit;
}

Fixed::Fixed(const float input)
{
	std::cout << "-> Float Constructor Called" << std::endl;
	value = roundf(input) * 256;
}

//Operator
Fixed& Fixed::operator = (const Fixed& input)
{
	std::cout << "Copy assignment = operator called" << std::endl;
	if (this == &input)
		return (*this);

	value = input.value;

	return (*this);
}

std::ostream& operator << (std::ostream &out, const Fixed &input)
{
	out << input.toFloat();
	return (out);
}


//Member Funtion
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

float Fixed::toFloat(void) const
{
	float temp;

	temp = ((float)value) / 256;

	return (temp);
}

int Fixed::toInt(void) const
{
	int temp;

	temp = value >> fractional_bit;
	
	return (temp);
}
