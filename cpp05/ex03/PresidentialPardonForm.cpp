
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig)
{
	*this = orig;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &orig)
{
	this->target = orig.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if(checkExec(executor))
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
