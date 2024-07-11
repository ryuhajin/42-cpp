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
	BitcoinExchange(const BitcoinExchange& rhs);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

};

#endif