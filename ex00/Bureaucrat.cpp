#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade)
{
	if (grade > 150 || grade < 1)
		throw (Bureaucrat(grade));
	std::cout << "A bureaucrat was born" << std::endl;
	this->grade = grade;
}

const char *Bureaucrat::what() const throw()
{
	if (this->grade > 150)
		return ("Bureaucrat::GradeTooLowException");
	else if (this->grade < 1)
		return ("Bureaucrat::GradeTooHighException");
	return ("a?");
};

int Bureaucrat::getGrade(){ return (this->grade); }

std::string Bureaucrat::getName(){ return (this->name); }

void Bureaucrat::incrementGrade(){ this->grade--; }

void Bureaucrat::decrementGrade(){ this->grade++; }

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "A bureaucrat died" << std::endl;
}
