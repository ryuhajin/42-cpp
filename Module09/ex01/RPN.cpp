#include "RPN.hpp"
#include <iostream>


RPN::RPN()
{}

RPN::RPN(const RPN& other)
	:_stack(other._stack)
{}

RPN& RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);

	this->_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{}

bool RPN::my_isdigit (char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool RPN::vaildInput (std::string& token)
{
	if (token.size() == 1 && my_isdigit(token[0]))
		_stack.push(token[0] - '0');
	else if (token == "+" || token == "-" || token == "*" || token == "/")
	{
		if (_stack.size() < 2)
		{
			std::cerr << "Error : Invalid input." << std::endl;
			return (false);
		}
		inputInStack(token[0]);
	}
	else
	{
		std::cerr << "Error : Invalid input." << std::endl;
		return (false);
	}
	return (true);
}

void RPN::inputInStack(char mathOperator)
{	
	int second = _stack.top();
	_stack.pop();

	int first = _stack.top();
	_stack.pop();

	int result = calculator(first, second, mathOperator);
	_stack.push(result);
}

int RPN::calculator (int first, int second, char mathOperator)
{
	int result;
	switch (mathOperator)
	{
	case '+' :
		result =  first + second;
		break;
	
	case '-' :
		result =  first - second;
		break;

	case '/' :
		if (second == 0)
		{
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
		result = first / second;
		break;

	case '*' :
		result = first * second;
		break;
	}

	return (result);
}


int RPN::getResult (void)
{
	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		std::exit(1);
	}
	
	return (_stack.top());
}
