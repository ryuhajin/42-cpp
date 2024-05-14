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

	std::string input(argv[1]);
	Harl harl;

	harl.complain(input);

	return (0);
}
