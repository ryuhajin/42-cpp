# ifndef FIXED_H
#define FIXED_H

class Fixed
{
private:
	static const int fractional_bit = 8;
	int	value;
public:
	Fixed();
	Fixed(const Fixed& input);
	~Fixed();

	Fixed& operator = (const Fixed& input);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif