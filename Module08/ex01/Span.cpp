#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits> 

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
	if(this->_size <= this->_numbers.size())
		throw std::out_of_range("size if pull. Cannot add value.");

	if (std::find(this->_numbers.begin(), this->_numbers.end(), value) != this->_numbers.end())
		throw std::invalid_argument("Cannot add value: Duplicate found.");

	_numbers.push_back(value);
}

int Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::out_of_range("Cannot find the shortestspan. because the size is too small.");
	
	std::vector<int> sortedSpan(_numbers);
	std::sort(sortedSpan.begin(), sortedSpan.end());

	int shortest_span = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedSpan.size(); i++)
	{
		int span = sortedSpan[i] - sortedSpan [i -1];
		if (span < shortest_span)
			shortest_span = span;
	}
	return (shortest_span);
}

int Span::longestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::out_of_range("Cannot find the shortestspan. because the size is too small.");
	
	std::vector<int> sortedSpan(_numbers);
	std::sort(sortedSpan.begin(), sortedSpan.end());

	int min = *(std::min_element(_numbers.begin(), _numbers.end()));
	int max = *(std::max_element(_numbers.begin(), _numbers.end()));

	return (max - min);
}

void Span::print_value(void)
{
	for (std::vector<int>::iterator it = this->_numbers.begin();
		it != this->_numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int> Span::getNumbers (void) const
{
	return (this->_numbers);
}
