#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{}

BitcoinExchange::~BitcoinExchange()
{}

bool checkData (std::string& line)
{
	
}

void setData (std::ifstream& file)
{
	std::string line;
	while (std::getline(file, line))
	{

	}
}

bool initData(std::string& fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error : file open failed." << std::endl;
		return (false);
	}


}