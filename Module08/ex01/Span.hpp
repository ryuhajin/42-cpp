#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits> //ㅎㅔ더 c++98 건지 확인필요

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
	void	print_value(void) const;

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (this->_size <= this->_numbers.size())
				throw std::out_of_range("size if pull. Cannot add value.");

			_numbers.push_back(*begin);
			++begin;
    	}
	}
};

#endif