#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	std::vector<int> _numbers;
	unsigned int _size;
public:
	Span();
	Span(unsigned int size);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);
	
	void	addNumber(int value);
	int		shortestSpan(void);
	int		longestSpan(void);
};

#endif