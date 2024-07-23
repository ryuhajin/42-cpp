#include "RPN.hpp"
#include <iostream>
#include <string>
#include <sstream>


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error : Invalid input." << std::endl;
		return (1);
	}

	RPN rpn;

	std::istringstream ss(argv[1]);
	std::string token;
	while (ss >> token)
	{
		if (!rpn.vaildInput(token))
			return (1);
	}

	std::cout << rpn.getResult() << std::endl;

	return (0);
}
