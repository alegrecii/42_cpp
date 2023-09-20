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

int	Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		if (!form.getIsSigned())
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		else
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because is already signed!"<<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low!"<<std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	std::cout<<this->name << " is trying to execute " << form.getName() << std::endl;
	form.execute(*this);
	std::cout<<this->name << " executed " << form.getName() << std::endl;
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

