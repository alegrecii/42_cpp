#include "ScalarConverter.hpp"

//---------------------------------CONSTRUCTORS---------------------------------

ScalarConverter::ScalarConverter()
{
	intOverflow = false;
	floatOverflow = false;
	charDisplayable = true;
	c = 0;
	i = 0;
	f = 0;
	d = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &original)
{
	*this = original;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &original)
{
	(void)original;
	return (*this);
}

//---------------------------------PRINTERS------------------------------------

void ScalarConverter::precisionSetter(const std::string &value)
{
	int precision = 1;
	if(value.find('.') != std::string::npos)
		precision = value.length() - value.find('.') - 2;
	if (precision < 1)
		precision = 1;
	if (precision > 6)
		precision = 6;
	std::cout << std::fixed << std::setprecision(precision);
}

void ScalarConverter::printChar()
{
	std::cout << "char: ";
	if (!charDisplayable)
		std::cout << "impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::printInt()
{
	if (!intOverflow)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat()
{
	if (!floatOverflow)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::printDouble()
{

	std::cout<< "double: " << d << std::endl;
}


//---------------------------------CONVERTERS----------------------------------

bool errorChecker(const std::string &value)
{
	int i = 0;
	bool dot = false;
	bool f = false;
	if (value.length() == 1 && !isdigit(value[0]))
		return (true);
	if (value[i] == '-' || value[i] == '+')
		i++;
	while(value[i])
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.' && !dot)
				dot = true;
			else if (value[i] == 'f' && !f)
				f = true;
			else
			{
				std::cout << "Error: Invalid input" << std::endl;
				return (false);
			}
		}
		i++;
	}
	return (true);
}

bool specialChecker(const std::string &value)
{
	if (value.find("nan") != std::string::npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (value.find("-inf") != std::string::npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (value.find("+inf") != std::string::npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (errorChecker(value))
		return (true);
	return (false);
}

void ScalarConverter::charConverter()
{
	if (c < 32 || c > 126)
		charDisplayable = false;
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

void ScalarConverter::floatConverter()
{
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		intOverflow = true;
	else
		i = static_cast<int>(f);
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
		charDisplayable = false;
	else
		c = static_cast<char>(f);
	d = static_cast<double>(f);
}

void ScalarConverter::doubleConverter()
{
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		intOverflow = true;
	else
		i = static_cast<int>(d);
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		charDisplayable = false;
	else
		c = static_cast<char>(d);
	if (std::abs(d) > std::numeric_limits<float>::max())
		floatOverflow = true;
	else
		f = static_cast<float>(d);
}

void ScalarConverter::intConverter()
{
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		charDisplayable = false;
	else
		c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}

void ScalarConverter::typeFinder(const std::string &value)
{
	if (value.length() == 1 && !isdigit(value[0]))
	{
		c = value[0];
		charConverter();
	}
	else if (value.find('f') != std::string::npos)
	{
		f = std::strtof(value.c_str(),NULL);
		floatConverter();
	}
	else if (value.find('.') != std::string::npos)
	{
		d = std::strtod(value.c_str(),NULL);
		doubleConverter();
	}
	else
	{
		long int l = strtol(value.c_str(),NULL, 10);
		if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
			throw OverflowException();
		i = std::atoi(value.c_str());
		intConverter();
	}
	if (errno == ERANGE)
	{
		throw OverflowException();
	}
}

void ScalarConverter::convert(const std::string &value)
{

	if(!specialChecker(value))
		return;

	ScalarConverter converter;
	try
	{
		converter.typeFinder(value);
		converter.precisionSetter(value);
		converter.printChar();
		converter.printInt();
		converter.printFloat();
		converter.printDouble();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

//---------------------------------DESTRUCTOR----------------------------------

ScalarConverter::~ScalarConverter()
{
}
