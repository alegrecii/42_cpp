#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}


std::map<std::string,std::string> BitcoinExchange::map_filler(std::ifstream &file)
{
	std::string line;
	std::map<std::string, std::string> map;
	std::getline(file,line);
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

bool dateChecker(int &year, int &month, int &day, std::string date)
{
	if (date.length() != 10)
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (date[i] != '-' && (i == 4 || i == 7))
			return false;
		else if (!isdigit(date[i]) && i != 4 && i != 7)
			return false;
		if (date[i] == '-')
			date[i] = ' ';
	}
	std::istringstream iss(date);
	iss >> year >> month >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

bool valueChecker(std::string &value, double &v)
{
	v = std::strtod(value.c_str(),NULL);
	if (v < 0)
		std::cout << "Error: not a positive number" << std::endl;
	else if (v > 1000)
		std::cout << "Error: too large number" << std::endl;
	else
		return true;
	return false;
}

double BitcoinExchange::rateFounder(std::string &date)
{
	std::map<std::string, std::string>::iterator it;
	std::string rate = "0";
	for (it = conv.begin(); it != conv.end(); it++)
	{
		if (it->first.compare(date) > 0)
			break;
		rate = it->second;
		if (it->first.compare(date) == 0)
			break;
	}
	return std::strtod(rate.c_str(),NULL);
}

void BitcoinExchange::value_printer(std::string &date, std::string &value)
{
	int year;
	int month;
	int day;
	double v;
	if(!dateChecker(year, month, day, date))
	{
		std::cout << "Error: date not recognized" << std::endl;
		return;
	}
	if (!valueChecker(value,v))
		return;

	double cRate = rateFounder(date);
	std::cout << date << " => " << value << " = " << cRate  * v << std::endl;
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
		std::cout << "Error: Value not recognized in this line" << std::endl;
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
