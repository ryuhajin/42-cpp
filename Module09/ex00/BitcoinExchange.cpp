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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_data = other._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);

	this->_data = other._data;

	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::checkLine(const std::string& line, const std::string& delimiter, size_t idx)
{
	size_t delim = line.find(delimiter);
	// std::cout << "line  : " << line << '\n' << std::endl;
	// std::cout << "delim len = " << delim << '\n' << std::endl;
	if (delim != idx)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::checkIss(const std::istringstream& ss)
{
	if (ss.fail())
		return (false);
	else if (!(ss.eof()))
	{
		// std::cout << "checkIss not EOF!" << std::endl;
		return (false);
	}

	return (true);
}

bool BitcoinExchange::checkDate(const std::string& date)
{
	std::tm tm = {};

	// std::cout << date << '\n' << std::endl;
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	// std::cout << "tm year: " << tm.tm_year + 1900 << ", Month: " << tm.tm_mon << ", Day: " << tm.tm_mday << '\n' << std::endl;
	if (ss.fail() || tm.tm_year + 1900 < 0 || tm.tm_mon < 0 || tm.tm_mon  > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
	{
		std::cerr << "Error : Date is not in the correct format. => " << date << std::endl;
		return (false);
	}

	std::tm original_tm = tm;
	std::mktime(&tm);

	// std::cout << "original year: " << original_tm.tm_year << ", Month: " << original_tm.tm_mon << ", Day: " << original_tm.tm_mday << std::endl;
	// std::cout << "mktime-> tm year: " << tm.tm_year << ", Month: " << tm.tm_mon << ", Day: " << tm.tm_mday << '\n' << std::endl;
	
	if (original_tm.tm_year != tm.tm_year || original_tm.tm_mon != tm.tm_mon || original_tm.tm_mday != tm.tm_mday)
	{
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }

	return (true);
}

bool BitcoinExchange::checkValue(const std::string& sval, double& value)
{
    std::istringstream ss(sval);
	ss >> value;

	if (!checkIss(ss))
	{
		std::cerr << "Error : Value is not in the correct format. => " << sval << std::endl;
        return (false);
    }
	else if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}

    return (true);
}

void BitcoinExchange::printExchange(const std::string& date, double& value)
{
	std::map<std::string, double>::iterator it = this->_data.lower_bound(date);

	if (it == _data.end())
		std::cout << "Error : No dates near you were found." << std::endl;
	else
	{
		std::cout << "value : " << it->second << " amount : " << value << std::endl;
		std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
	}
}

bool BitcoinExchange::initData(std::string fileName)
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
		if (!checkLine(line, ",", 10))
			return  (false);
		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, ',');
		if (!checkDate(date))
			return (false);
		double value;
		ss >> value;
		if (!checkIss(ss))
			return (false);
		_data[date] = value;
    }
	return (true);
}

bool BitcoinExchange::inputExchange(std::string fileName)
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
		if (!checkLine(line, " | ", 10))
			continue;
		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, '|');
		if (!checkDate(date))
			continue;
		std::string sval;
		ss >> sval;
		double value;
		if (!checkValue(sval, value))
			continue;
		printExchange(date, value);
    }
	return (true);
}
