#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//ctime, mktimev <- input 년월일시 체크
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool checkIss(const std::istringstream& ss);
	bool checkDate(const std::string& date);
	bool checkValue(std::istringstream& ss, float& value);
	void printExchange(const std::string& date, float& value);
	bool initData(std::string fileName);
	bool inputExchange(std::string fileName);
};

#endif