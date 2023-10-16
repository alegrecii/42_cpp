#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, std::string> conv;
	std::ifstream *input;
	std::map<std::string, std::string> map_filler(std::ifstream &file);
	BitcoinExchange();
	void value_printer(std::string &date, std::string &value);
	bool input_checker(std::string &line, std::string &date, std::string &value);
public:
	BitcoinExchange(std::ifstream &file);
	BitcoinExchange(BitcoinExchange &original);
	BitcoinExchange &operator=(BitcoinExchange &original);
	void converter();
	~BitcoinExchange();
};
