#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please insert only one argument" << std::endl;
		return 0;
	}
	std::string input = argv[1];
	RPN rpn;
	rpn.calculate(input);
}
