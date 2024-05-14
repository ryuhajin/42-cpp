#include "Harl.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "->input error." << std::endl;
		exit(1);
	}

	Harl harl;

	std::string input(argv[1]);
	harl.complain(input);

	return (0);
}
