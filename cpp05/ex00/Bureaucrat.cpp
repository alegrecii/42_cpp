#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "Default";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

std::string	Bureaucrat::getName()
{
	return (this->name);
}

int	Bureaucrat::getGrade()
{
	return (this->grade);
}

void	Bureaucrat::upgrade()
{
	if (this->grade < 2)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::downgrade()
{
	if (this->grade > 149)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
	os<< b.getName() <<" Bureaucrat grade " << b.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat "<< this->name << " died" << std::endl;
}

