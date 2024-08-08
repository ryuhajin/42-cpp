#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double, std::greater<std::string> > _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool findDelimiter(const std::string& line, const std::string& delimiter, size_t idx);
	bool streamStatusCheck(std::string &str, double &value);
	bool dateParser(const std::string &date, std::tm &tm);
	bool vaildDate(const std::string& date);
	bool vaildValue(double& value);
	void printExchange(const std::string& date, double& value);
	bool initData(std::string fileName);
	bool inputExchange(std::string fileName);
};

#endif