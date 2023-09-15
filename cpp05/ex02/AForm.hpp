#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const int gradetoSign;
	bool isSigned;
	const int gradetoExec;

public:
	AForm();
	AForm(std::string name, int gradetoSign, int gradetoExec);
	AForm(AForm &original);
	~AForm();
	AForm	&operator=(AForm &original);
	bool getIsSigned();
	int getGradeToSign();
	int getGradeToExec();
	std::string	getName();
	void	beSigned(Bureaucrat &b);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("Exception in the form occurred, Grade too high!");
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("Exception in the form occurred, Grade too low!");
			}
	};
};

std::ostream &operator<<(std::ostream &os, AForm &f);
#endif
