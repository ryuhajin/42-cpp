#include "Fixed.h"
#include <iostream>

int main( void )
{
	Fixed a = 100;
	Fixed const b = 10.016f;
	Fixed const c = -125;
	Fixed d = -42.42f;

	std::cout << "a: " << a << " b: " << b << " a - b : " << a - b << std::endl;
	
	std::cout << "a: " << a << " c: " << c << " a - c : " << a - c << std::endl;
	
	std::cout << "a: " << a << " b: " << b << " a + b : " << a + b << std::endl;
	
	std::cout << "a: " << a << " d: " << d << " a + d : " << a + d << std::endl;
	
	std::cout << "c: " << c << " d: " << d << " c * d : " << c * d << std::endl;
	
	std::cout << "b: " << b << " d: " << d << " b * d : " << c * d << std::endl;
	
	std::cout << "a: " << a << " b: " << b << " a / b : " << a / b << std::endl;
	
	std::cout << "c: " << c << " d: " << d << " c / d : " << c / d << std::endl;
	
	std::cout << "d: " << d << " c: " << c << " d / c : " << d / c << std::endl;


	return (0);
}
