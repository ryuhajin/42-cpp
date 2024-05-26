#include "Fixed.h"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const int input)
{
	std::cout << "[Constructor] int : " << input << " Called" << std::endl;
	value = input << fractional_bit;
}

Fixed::Fixed(const float input)
{
	std::cout << "[Constructor] float : " << input << " Called" << std::endl;
	value = roundf(input * 256.0f);
}

//Operator
Fixed& Fixed::operator = (const Fixed& input)
{
	std::cout << "[Operator] Copy assignment called" << std::endl;
	if (this == &input)
		return (*this);

	value = input.value;

	return (*this);
}

bool	Fixed::operator > (const Fixed& input) const
{
	return (value > input.getRawBits());
}

bool	Fixed::operator < (const Fixed& input) const
{
	return (value < input.getRawBits());
}

bool	Fixed::operator >= (const Fixed& input) const
{
	return	(value >= input.getRawBits());
}

bool	Fixed::operator <= (const Fixed& input) const
{
	return (value <= input.getRawBits());
}

bool	Fixed::operator == (const Fixed& input) const
{
	return (value == input.getRawBits());
}

bool	Fixed::operator != (const Fixed& input) const
{
	return (value != input.getRawBits());
}

Fixed Fixed::operator + (const Fixed& input) const
{
	Fixed temp;
	temp.setRawBits(value + input.getRawBits());
	return (temp);
}

Fixed Fixed::operator - (const Fixed& input) const
{
	Fixed	temp;
	temp.setRawBits(value - input.getRawBits());
	return (temp);
}

Fixed Fixed::operator * (const Fixed& input) const
{
	Fixed	temp;
	temp.setRawBits(value * input.getRawBits() / 256);
	return (temp);
}

Fixed Fixed::operator / (const Fixed& input) const
{
	Fixed	temp;
	temp.setRawBits((value << 8) / input.getRawBits());
	return (temp);
}

Fixed& Fixed::operator ++ (void)
{
	++value;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp(*this);
	++value;
	return (temp);
}

Fixed& Fixed::operator -- (void)
{
	--value;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed temp(*this);
	--value;
	return (temp);
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

	temp = ((float)value) / 256.0f;

	return (temp);
}

int Fixed::toInt(void) const
{
	int temp;

	temp = value >> fractional_bit;
	
	return (temp);
}

//static member function
Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	else
		return (f2);
}

//Function
void print_bit(unsigned char *ptr, int size)
{
	std::cout << "bit : ";
	for(int i = size - 1; i >= 0; i--)
	{
		for(int j = 7; j > -1; j--)
		{
			std::cout << (((*(ptr + i)) >> j & 1) ? 1 : 0);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
