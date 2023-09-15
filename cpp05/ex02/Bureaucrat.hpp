#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int	grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &original);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &original);
		std::string	getName();
		int	getGrade();
		void	upgrade();
		void	downgrade();
		void	signForm(AForm &form);
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("Exception occurred, Grade too high!");
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("Exception occurred, Grade too low!");
			}
	};

};
std::ostream &operator<<(std::ostream &os, Bureaucrat &b);
#endif
