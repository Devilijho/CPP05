#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("defaultAForm"), gradeToSign(75), gradeToExecute(75), isSigned(false), target("defaultTarget"){}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, bool isSigned, std::string target)
: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(isSigned), target(target)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
	std::cout << "AForm created successfully" << std::endl;
}

AForm::AForm(const AForm &other):
  name(other.getName())
, gradeToSign(other.getGradeToSign())
, gradeToExecute(other.getgradeToExecute())
, isSigned(getSign())
{
	std::cout << "AForm created successfully" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (&other != this)
		this->isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destroyed successfully" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw(){ return ("AForm::GradeTooHighException"); };

const char *AForm::GradeTooLowException::what() const throw(){ return ("AForm::GradeTooLowException"); };

const char *AForm::NotSignedException::what() const throw(){ return ("AForm::NotSignedException"); };

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	std::string signature;

	if (form.getSign() == true)
		signature = "yes";
	else
		signature = "no";
	out << "AForm " << form.getName() <<
	", form grade to sign required is " << form.getGradeToSign() <<
	", form grade to execute required is " << form.getgradeToExecute() <<
	", form is signed: "<< signature;
	return out;
}

std::string AForm::getName() const { return (this->name); }

int			AForm::getGradeToSign() const { return (this->gradeToSign); }

int			AForm::getgradeToExecute() const { return (this->gradeToExecute); }

bool		AForm::getSign() const { return ( this->isSigned ); }

std::string	AForm::getTarget() const { return (this->target); }

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	else
		throw GradeTooLowException();

}
void AForm::execute() const{}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->isSigned == true && executor.getGrade() <= this->getgradeToExecute())
		this->execute();
	else if (this->isSigned == false)
		throw NotSignedException();
	else
		throw GradeTooLowException();
}
