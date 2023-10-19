#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
		std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &orig);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &orig);
	void	execute(Bureaucrat const & executor) const;
	virtual ~PresidentialPardonForm();
};

#endif
