#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "Default";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	//exceptions check
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &original)
{
	*this = original;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &original)
{
	this->name = original.name;
	this->grade = original.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat "<< this->name << " died" << std::endl;
}
