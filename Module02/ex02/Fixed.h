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
	bool	operator > (const Fixed& input);
	bool	operator < (const Fixed& input);
	bool	operator >= (const Fixed& input);
	bool	operator <= (const Fixed& input);
	bool	operator == (const Fixed& input);
	bool	operator != (const Fixed& input);

	Fixed	operator + (const Fixed& input);
	Fixed	operator - (const Fixed& input);
	Fixed	operator * (const Fixed& input);
	Fixed	operator / (const Fixed& input);

	Fixed&	operator ++ (void);
	Fixed operator ++ (int);

	// Fixed& operator -- (void);
	// Fixed& operator -- (int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator << (std::ostream &out, const Fixed &input);
void print_bit(unsigned char *ptr, int size);

#endif