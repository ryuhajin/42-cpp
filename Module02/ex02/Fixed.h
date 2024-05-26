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

	bool	operator > (const Fixed& input) const;
	bool	operator < (const Fixed& input) const;
	bool	operator >= (const Fixed& input) const;
	bool	operator <= (const Fixed& input) const;
	bool	operator == (const Fixed& input) const;
	bool	operator != (const Fixed& input) const;

	Fixed	operator + (const Fixed& input) const;
	Fixed	operator - (const Fixed& input) const;
	Fixed	operator * (const Fixed& input) const;
	Fixed	operator / (const Fixed& input) const;

	Fixed&	operator ++ (void);
	Fixed	operator ++ (int);

	Fixed&	operator -- (void);
	Fixed	operator -- (int);

	//function
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	//static function
	static		 Fixed&	min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static		 Fixed&	max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator << (std::ostream &out, const Fixed &input);
void print_bit(unsigned char *ptr, int size);

#endif