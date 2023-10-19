#include "Intern.hpp"

AForm *Intern::createPPF(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRRF(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createSCF(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::error(std::string target)
{
	(void) target;
	throw NoMatchesException();
	return (NULL);
}

Intern::Intern()
{
}

Intern::Intern(Intern const &original)
{
	*this = original;
}

Intern Intern::operator=(Intern const &original)
{
	(void) original;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm	*(Intern::*funcs[4])(std::string target) = {&Intern::createPPF, &Intern::createRRF, &Intern::createSCF, &Intern::error};
	std::string	compare[3] = {"presidential pardon","robotomy request", "shrubbery creation" };
	int chosen = 3;
	for (int i = 0; i < 3; i++)
		if (name == compare[i])
			chosen = i;
	return((this->*funcs[chosen])(target));
}

Intern::~Intern()
{
}

