#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{

	Bureaucrat	john("John",3);
	Bureaucrat	mark("Mark", 29);
	try
	{
		PresidentialPardonForm PPF("mark");
		john.executeForm(PPF);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		ShrubberyCreationForm SCF("Mark");
		john.signForm(SCF);
		john.executeForm(SCF);
		std::cout << std::endl;

		RobotomyRequestForm RRF("Paul");
		mark.signForm(RRF);
		mark.executeForm(RRF);
		std::cout << std::endl;

		PresidentialPardonForm PPF("Jack");
		john.signForm(PPF);
		john.executeForm(PPF);
		mark.executeForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
