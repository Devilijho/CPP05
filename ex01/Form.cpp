#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("defaultForm"), gradeToSign(75), gradeToExecute(75), isSigned(false){}

Form::Form(std::string name, int gradeToSign, int gradeToExecute, bool isSigned)
: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(isSigned)
{
	std::cout << "Form created successfully" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &other):
  name(other.getName())
, gradeToSign(other.getGradeToSign())
, gradeToExecute(other.getgradeToExecute())
, isSigned(getSign()){}

Form &Form::operator=(const Form &other)
{
	if (&other != this)
		this->isSigned = other.isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destroyed successfully" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw(){ return ("Form::GradeTooHighException"); };

const char *Form::GradeTooLowException::what() const throw(){ return ("Form::GradeTooLowException"); };

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::string signature;

	if (form.getSign() == true)
		signature = "yes";
	else
		signature = "no";
	out << "form " << form.getName() <<
	", form grade to sign required is " << form.getGradeToSign() <<
	", form grade to execute required is " << form.getgradeToExecute() <<
	", form is signed: "<< signature;
    return out;
}

std::string Form::getName() const { return (this->name); }

int			Form::getGradeToSign() const { return (this->gradeToSign); }

int			Form::getgradeToExecute() const { return (this->gradeToExecute); }

bool		Form::getSign() const { return ( this->isSigned ); }

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}
