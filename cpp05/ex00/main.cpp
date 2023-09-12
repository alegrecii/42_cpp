#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat frank("frank", 93);
		Bureaucrat mark("mark", 180);
		Bureaucrat carl("carl", -1);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat bobby("bobby", 2);
	try
	{
		std::cout << bobby << std::endl;
		bobby.upgrade();
		std::cout << bobby << std::endl;
		bobby.upgrade();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
