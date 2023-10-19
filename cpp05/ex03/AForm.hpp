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
	bool isSigned;
	const int gradetoSign;
	const int gradetoExec;

public:
	AForm();
	AForm(std::string name, int gradetoSign, int gradetoExec);
	AForm(AForm &original);
	virtual ~AForm();
	AForm	&operator=(AForm &original);
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	std::string	getName() const;
	void	beSigned(Bureaucrat &b);
	bool	checkExec(const Bureaucrat &b) const;
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
	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("The form that you're trying to execute is not signed!");
			}
	};
};

std::ostream &operator<<(std::ostream &os, AForm &f);
#endif
