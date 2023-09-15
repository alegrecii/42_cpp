#include "AForm.hpp"

AForm::AForm() : name("default form"), isSigned(false),gradetoSign(150), gradetoExec(150)
{
}

AForm::AForm(std::string name, int gradetoSign, int gradetoExec) :name(name), isSigned(false), gradetoSign(gradetoSign), gradetoExec(gradetoExec)
{
	if (gradetoSign > 150 || gradetoExec > 150)
		throw AForm::GradeTooLowException();
	if (gradetoSign < 1 || gradetoExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm &original) :name(original.name), isSigned(original.isSigned), gradetoSign(original.gradetoSign), gradetoExec(original.gradetoExec)
{
}

AForm &AForm::operator=(AForm &original)
{
	this->isSigned = original.isSigned;
	return (*this);
}

bool AForm::getIsSigned()
{
	return (isSigned);
}

int AForm::getGradeToSign()
{
	return (gradetoSign);
}

int AForm::getGradeToExec()
{
	return (gradetoExec);
}

std::string AForm::getName()
{
	return (name);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (gradetoSign < b.getGrade())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, AForm &f)
{
	os<< f.getName() <<" Form informations:" << std::endl << "Signed: " << f.getIsSigned() << std::endl << "Grade required to sign: " << f.getGradeToSign() << std::endl << "Grade required to execute: " << f.getGradeToExec() << std::endl;
	return (os);
}

AForm::~AForm()
{
}
