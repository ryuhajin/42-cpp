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
		std::cerr << "Error : Date is not in the correct format. => " << date << std::endl;
		return (false);
	}

	std::tm original_tm = tm; 
	std::mktime(&tm);

	if (original_tm.tm_year != tm.tm_year || original_tm.tm_mon != tm.tm_mon || original_tm.tm_mday != tm.tm_mday)
	{
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }

	return (true);
}

bool checkValue(const std::string& value)
{
    std::istringstream ss(value);
    float val;
    ss >> val;

	if (ss.fail() || !(ss.eof()))
	{
		std::cerr << "Error : Value is not in the correct format. => " << value << std::endl;
        return (false);
    }
	else if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}

    return (true);
}

bool initData(std::string& fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error : data file open failed." << std::endl;
		return (false);
	}

	std::string head;
	std::getline(file, head);
	if (!("date,exchange_rate" == head))
	{
		std::cerr << "Error : data Not a valid head format." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, ',');
		if (!checkDate(date))
			return (false);
		std::string value;
		ss >> value;
		if (!checkValue(value))
			return (false);
		this->_data[date] = value;
    }
	return (true);
}

bool inputExchange(std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cerr << "Error : input file open failed." << std::endl;
		return (false);
	}

	std::string head;
	std::getline(file, head);
	if (!("date | value" == head))
	{
		std::cerr << "Error : input Not a valid head format." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, '|');
		if (!checkDate(date))
			continue;
		std::string value;
		ss >> value;
		if (!checkValue(value))
			continue;
		this->_data[date] = value;
    }
	return (true);
}