#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please insert one argument"<< std::endl;
		return (0);
	}
	std::ifstream file(argv[1]);

	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (0);
	}

	


}
