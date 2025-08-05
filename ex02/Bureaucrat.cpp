#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(75)
{
	std::cout << "A bureaucrat was born" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	std::cout << "A bureaucrat was born" << std::endl;
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
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat died" << std::endl;
}
