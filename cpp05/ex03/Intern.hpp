#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	AForm *createPPF(std::string target);
	AForm *createRRF(std::string target);
	AForm *createSCF(std::string target);
	AForm *error(std::string target);

public:
	Intern();
	Intern(Intern const &original);
	Intern	operator=(Intern const &original);
	AForm	*makeForm(std::string name, std::string target);

	class NoMatchesException : public std::exception {
		public:
			virtual const char* what() const throw()
			{
				return("This intern can't find the form that was requested!");
			}
	};
	~Intern();
};
