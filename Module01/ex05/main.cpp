#include "Harl.h"
#include <iostream>
#include <string>

int main(void)
{
	Harl harl;

	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");

	std::cout << "[ DEBUG ]" <<std::endl;
	harl.complain("DEBUG");

	std::cout << "[ WARNING ]" <<std::endl;
	harl.complain("WARNING");

	std::cout << "[ ERROR ]" <<std::endl;
	harl.complain("ERROR");

	std::cout << std::endl;
	return (0);
}
