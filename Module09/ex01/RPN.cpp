#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& rhs)
{}

RPN& RPN::operator=(const RPN& rhs)
{}

RPN::~RPN()
{}
int calculator (int num1, int num2, std::string& math_operator)
{
	int result;
	switch (math_operator)
	{
	case "+" :
		result = num1 + num2;
		break;
	
	case "-" :
		result = num1 - num2;
		break;

	case "/" :
		if (num2 == 0)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		result = num1 / num2;
		break;

	case "*" :
		result = num1 * num2;
		break;

	default:
		std::cerr << "Error" << std::endl;
		exit(1);
	}

	return (result);
}

