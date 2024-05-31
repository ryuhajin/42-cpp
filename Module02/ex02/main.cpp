#include "Fixed.h"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;

	int one = 1;
	float one_f = (float)one;
	unsigned char * one_p = (unsigned char *)&one_f;
	std::cout << "1.0f ";
	print_bit(one_p, sizeof(float));
	float bit = 256.0f;
	unsigned char * b_p = (unsigned char *)&bit;
	std::cout << "256.0 ";
	print_bit (b_p, sizeof(float));
	float a_ = ((float)one) / 256.0f;
	std::cout << "1 / 256.0f ";
	unsigned char *prt = (unsigned char *)&a_;
	print_bit(prt, sizeof(float));

	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
