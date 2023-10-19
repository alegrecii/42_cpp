#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradetoSign;
	const int gradetoExec;

public:
	Form();
	Form(std::string name, int gradetoSign, int gradetoExec);
	Form(Form &original);
	~Form();
	Form	&operator=(Form &original);
	bool getIsSigned();
	int getGradeToSign();
	int getGradeToExec();
	std::string	getName();
	void	beSigned(Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &os, Form &f);
#endif
