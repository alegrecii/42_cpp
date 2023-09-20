#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
		std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &orig);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &orig);
	void	execute(Bureaucrat const & executor) const override;
	virtual ~RobotomyRequestForm();
};

#endif
