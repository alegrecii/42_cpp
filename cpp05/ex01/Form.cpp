#include "Form.hpp"

Form::Form() : name("default form"), isSigned(false),gradetoSign(150), gradetoExec(150)
{
}

Form::Form(std::string name, int gradetoSign, int gradetoExec) :name(name), isSigned(false), gradetoSign(gradetoSign), gradetoExec(gradetoExec)
{
	if (gradetoSign > 150 || gradetoExec > 150)
		throw Form::GradeTooLowException();
	if (gradetoSign < 1 || gradetoExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form &original) :name(original.name), isSigned(original.isSigned), gradetoSign(original.gradetoSign), gradetoExec(original.gradetoExec)
{
}

Form &Form::operator=(Form &original)
{
	this->isSigned = original.isSigned;
	return (*this);
}

bool Form::getIsSigned()
{
	return (isSigned);
}

int Form::getGradeToSign()
{
	return (gradetoSign);
}

int Form::getGradeToExec()
{
	return (gradetoExec);
}

std::string Form::getName()
{
	return (name);
}

void Form::beSigned(Bureaucrat &b)
{
	if (gradetoSign < b.getGrade())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form &f)
{
	os<< f.getName() <<" Form informations:" << std::endl << "Signed: " << f.getIsSigned() << std::endl << "Grade required to sign: " << f.getGradeToSign() << std::endl << "Grade required to execute: " << f.getGradeToExec() << std::endl;
	return (os);
}

Form::~Form()
{
}
