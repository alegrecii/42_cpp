#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string name;
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
