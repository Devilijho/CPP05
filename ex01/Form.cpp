#include "Form.hpp"

Form::Form(): name("defaultForm"), gradeToSign(150), gradeToExecute(150), isSigned(false)
{
	std::cout << "Form created successfully" << std::endl;
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
	out << form.getName() <<
	", form required to sign grade: " << form.getGradeToSign() <<
	", form required to execute grade: " << form.getgradeToExecute() <<
	", form is signed: "<< form.getSign()
	<< std::endl;
    return out;
}

std::string Form::getName() const { return (this->name); }

int			Form::getGradeToSign() const { return (this->gradeToSign); }

int			Form::getgradeToExecute() const { return (this->gradeToExecute); }

bool		Form::getSign() const { return ( this->isSigned ); }

void		Form::beSigned(Bureaucrat &bureaucrat) {}
