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

bool BitcoinExchange::findDelimiter(const std::string& line, const std::string& delimiter, size_t idx)
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

bool BitcoinExchange::streamStatusCheck(std::string &str, double &value)
{
	std::istringstream ss(str);
	ss >> value;

	if (ss.fail() || !(ss.eof()))
	{
		std::cerr << "Error: Value is not in the correct format. => " << str << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::dateParser(const std::string &date, std::tm &tm)
{
	std::istringstream ss(date);

	int year, month, day;
	char first_del, second_del;

	ss >> year >> first_del >> month >> second_del >> day;

	if (ss.fail() || first_del != '-' || second_del != '-')
        return (false);
	else if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

	tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

	return (true);
}


bool BitcoinExchange::vaildDate(const std::string& date)
{
	std::tm tm = {};

	if (!dateParser(date, tm))
	{
		std::cerr << "Error: Date is not in the correct format. => " << date << std::endl;
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

bool BitcoinExchange::vaildValue(double& value)
{
	if (value < 0)
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
		std::cout << "Error: No dates near you were found." << std::endl;
	else
	{
		// std::cout << "value : " << it->second << " amount : " << value << std::endl;
		std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
	}
}

bool BitcoinExchange::initData(std::string fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error: data file open failed." << std::endl;
		return (false);
	}

	std::string head;
	std::getline(file, head);
	if (!("date,exchange_rate" == head))
	{
		std::cerr << "Error: data Not a valid head format." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		if (!findDelimiter(line, ",", 10))
			return  (false);

		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, ',');
		if (!vaildDate(date))
			return (false);

		std::string str;
		std::getline(ss, str);
		double value;
		if (!streamStatusCheck(str, value))
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
		std::cerr << "Error: input file open failed." << std::endl;
		return (false);
	}

	std::string head;
	std::getline(file, head);
	if (!("date | value" == head))
	{
		std::cerr << "Error: input Not a valid head format." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\n\r") == std::string::npos)
			continue;
		if (!findDelimiter(line, " | ", 10))
			continue;

		std::istringstream ss(line);
        std::string date;
		std::getline(ss, date, '|');
		if (!vaildDate(date))
			continue;

		std::string str;
		std::getline(ss, str);
		double value;
		if (!streamStatusCheck(str, value))
			continue;
		if (!vaildValue(value))
			continue;
		printExchange(date, value);
    }
	return (true);
}
