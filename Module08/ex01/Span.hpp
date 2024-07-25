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
	
	void				addNumber(int value);
	int					shortestSpan(void);
	int					longestSpan(void);
	void				print_value(void);
	std::vector<int>	getNumbers (void) const;

	template <typename Iterator>
	void addNumbers(Iterator Vbegin, Iterator Vend)
	{
		while (Vbegin != Vend)
		{
			if (this->_size <= this->_numbers.size())
				throw std::out_of_range("size if pull. Cannot add value.");
			if (std::find(this->_numbers.begin(), this->_numbers.end(), *Vbegin) != this->_numbers.end())
				throw std::invalid_argument("Cannot add value: Duplicate found.");

			_numbers.push_back(*Vbegin);
			++Vbegin;
    	}
	}
};

#endif