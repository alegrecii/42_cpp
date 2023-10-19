#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
	target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig)
{
	*this = orig;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &orig)
{
	this->target = orig.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(checkExec(executor))
	{
		std::cout << "Vrrr...Vrrrrrrr..Vrrrr.." << std::endl;
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		if(std::rand()%2)
			std::cout << target << " has been robotmized" << std::endl;
		else
			std::cout << "Robotomy on " << target << " failed" << std::endl;
	}

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
