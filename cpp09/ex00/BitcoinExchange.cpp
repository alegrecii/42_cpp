#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

std::map<std::string,std::string> BitcoinExchange::map_filler(std::ifstream &file)
{
	std::string line;
	std::map<std::string, std::string> map;
	while(std::getline(file,line))
	{
		std::string key;
		std::string value;
		std::istringstream iss(line);
		std::getline(iss, key,',');
		std::getline(iss,value);
		map[key] = value;
	}
	return (map);
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string line;
	input = &file;
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw std::runtime_error("Error: could not open file");
	conv = map_filler(data);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &original)
{
	*this = original;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &original)
{
	this->conv = original.conv;
	return (*this);
}

void BitcoinExchange::value_printer(std::string &date, std::string &value)
{
	(void) date;
	(void) value;
	std::cout << "OK" << std::endl;
}

bool isNumeric(std::string &str)
{
	size_t i = 0;
	int dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while(i < str.length())
	{
		if (str[i] == '.' && dot == 0)
			dot++;
		else if(!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool BitcoinExchange::input_checker(std::string &line, std::string &date, std::string &value)
{
	std::string token;

	std::istringstream iss(line);

	iss >> date >> token >> value;
	if (token.compare("|"))
	{
		std::cout << "Syntax error in this line" << std::endl;
		return false;
	}
	if (iss.fail())
	{
		std::cout << "Error" << std::endl;
		return false;
	}
	iss >> token;
	if (!iss.fail())
	{
		std::cout << "Error: too many arguments in this line" << std::endl;
		return false;
	}
	if (!isNumeric(value))
	{
		std::cout << "Value not recognized in this line" << std::endl;
		return false;
	}
		return true;
}

void BitcoinExchange::converter()
{
	std::string line;
	std::getline(*input, line);
	while(std::getline(*input, line))
	{
		std::string date;
		std::string value;
		if(input_checker(line, date, value))
			value_printer(date, value);
	}
}

BitcoinExchange::~BitcoinExchange()
{
}
