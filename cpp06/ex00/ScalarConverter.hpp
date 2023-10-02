#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cerrno>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &original);
	ScalarConverter &operator=(const ScalarConverter &original);
	void typeFinder(const std::string &value);
	void charConverter();
	void intConverter();
	void floatConverter();
	void doubleConverter();
	char c;
	int i;
	float f;
	double d;
	bool intOverflow;
	bool floatOverflow;
	bool charDisplayable;
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
	void precisionSetter(const std::string &value);
	class OverflowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("This value is out of range for his type!");
		}
	};

public:
	void static convert(const std::string &value);

	~ScalarConverter();
};


