#include "Bureaucrat.hpp"

int main()
{
	try
	{
		AForm a("A", 100, 50);
		AForm b("B", 170, 20);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat	bobby("Bobby", 2);
	Bureaucrat	mark("Mark", 108);
	AForm		a("A", 120, 50);
	AForm		b("B", 20, 10);
	try
	{
		std::cout << a;
		bobby.signForm(a);
		mark.signForm(a);
		std::cout << b;
		mark.signForm(b);
		bobby.signForm(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
