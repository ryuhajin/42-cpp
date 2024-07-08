#include "Span.hpp"

Span::Span()
	:_size(0)
{}

Span::Span(unsigned int size)
	:_size(size)
{}

Span::Span(const Span& other)
	:_numbers(other._numbers), _size(other._size)
{}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_numbers = other._numbers;
	_size = other._size;

	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int value)
{
	if(this->_size <= _value.size())
		throw std::out_of_range("size if pull. Cannot add value.");
	
	_numbers.push_back(value);
}

int Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::out_of_range("");
}