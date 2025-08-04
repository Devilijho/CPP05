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

std::string Form::getName() const { return (this->name); }
int			getGradeToSign() const {}
		int			getgradeToExecute() const;
		bool		getSign() const;
		void		beSigned(Bureaucrat &bureaucrat);
