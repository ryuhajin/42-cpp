#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{}

BitcoinExchange::~BitcoinExchange()
{}
bool checkDate(const std::string& date)
{
	std::tm tm = {0};
	std::istringstream ss(date);

	ss >> std::get_time(&tm, "%Y-%m-%d");

	if (ss.fail() || !(ss.eof()) || tm.tm_year < 0 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
	{
		std::cerr << "Error : Date is not in the correct format." << std::endl;
		return (false);
	}

	std::tm original_tm = tm; 
	std::mktime(&tm);

	if (original_tm.tm_year != tm.tm_year || original_tm.tm_mon != tm.tm_mon || original_tm.tm_mday != tm.tm_mday)
	{
        std::cerr << "Error: Date is not a valid date." << std::endl;
        return (false);
    }

	return (true);
}


bool initData(std::string& fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error : file open failed." << std::endl;
		return (false);
	}

	std::string head;
	std::getline(file, head);
	if (!("date,exchange_rate" == head))
	{
		std::cerr << "Error : Not a valid head format." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		std::istringstream ss(line);
        std::string date;
		std::getline(ss,date,'|')
    }
}
