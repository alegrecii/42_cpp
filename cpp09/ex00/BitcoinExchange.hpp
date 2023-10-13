#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, std::string> conv;
	std::map<std::string, std::string> input;
	BitcoinExchange();
public:
	BitcoinExchange(std::ifstream file);
	BitcoinExchange(BitcoinExchange &original);
	BitcoinExchange &operator=(BitcoinExchange &original);
	~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange()
{
}


BitcoinExchange::~BitcoinExchange()
{
}

