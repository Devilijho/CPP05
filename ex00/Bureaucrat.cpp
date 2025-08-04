#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	std::cout << "A bureaucrat was born" << std::endl;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){ return ("Bureaucrat::GradeTooHighException"); };

const char *Bureaucrat::GradeTooLowException::what() const throw(){ return ("Bureaucrat::GradeTooLowException"); };

int Bureaucrat::getGrade() const { return (this->grade); }

std::string Bureaucrat::getName() const { return (this->name); }

void Bureaucrat::incrementGrade(){ this->grade--; }

void Bureaucrat::decrementGrade(){ this->grade++; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat died" << std::endl;
}
