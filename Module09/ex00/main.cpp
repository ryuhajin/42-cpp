#include "BitcoinExchange.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error : Please check input file." << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	if (!btc.initData("data.csv"))
		return (1);

	if (!btc.inputExchange(argv[1]))
		return (1);

	return (0);
}
