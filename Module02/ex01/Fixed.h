# ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
private:
	static const int fractional_bit = 8;
	int	value;
public:
	Fixed();
	Fixed(const Fixed& input);
	Fixed(const int input);
	Fixed(const float input);
	~Fixed();

	Fixed& operator = (const Fixed& input);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator << (std::ostream &out, const Fixed &input);

#endif