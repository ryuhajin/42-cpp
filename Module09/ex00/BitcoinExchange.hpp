#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//ctime, mktimev <- input 년월일시 체크
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

	bool checkLine(const std::string& line, const std::string& delimiter, size_t idx);
	bool checkIss(const std::istringstream& ss);
	bool checkDate(const std::string& date);
	bool checkValue(const std::string& sval, double& value);
	void printExchange(const std::string& date, double& value);
	bool initData(std::string fileName);
	bool inputExchange(std::string fileName);
};

#endif