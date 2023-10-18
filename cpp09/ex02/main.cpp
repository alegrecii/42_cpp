#include "PmergeMe.hpp"

bool checkArg(std::string arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]))
			return (false);
	}
	if (atol(arg.c_str()) > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Please insert some arguments" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		if (!checkArg(argv[i]))
		{
			std::cout << "Wrong Args" << std::endl;
			return (0);
		}
	}
	std::string values;
	for (int i = 1; i < argc; i++)
	{
		values += argv[i];
		if (i != argc - 1)
			values += " ";
	}
	PmergeMe p;
	p.execute(argc -1, values);
	return (0);
}
