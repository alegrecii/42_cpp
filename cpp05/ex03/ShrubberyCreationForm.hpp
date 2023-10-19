#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
		std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &orig);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &orig);
	void	execute(Bureaucrat const & executor) const;
	virtual ~ShrubberyCreationForm();
};

#endif
