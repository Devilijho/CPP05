#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	std::cout << "A bureaucrat was born" << std::endl;
	this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){ return ("Bureaucrat::GradeTooHighException"); };

const char *Bureaucrat::GradeTooLowException::what() const throw(){ return ("Bureaucrat::GradeTooLowException"); };

int Bureaucrat::getGrade(){ return (this->grade); }

std::string Bureaucrat::getName(){ return (this->name); }

void Bureaucrat::incrementGrade(){ this->grade--; }

void Bureaucrat::decrementGrade(){ this->grade++; }

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat died" << std::endl;
}
