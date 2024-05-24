#include "Fixed.h"
#include <iostream>

int main( void )
{
	float a = 0.00002f;
	unsigned char * b = (unsigned char *)&a;

	print_bit(b, sizeof(float));

	return (0);

	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	// return (0);
}
