#pragma once

#include <ostream>
#define SUCCESS 0
#define ERROR 1

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();
		~Bureaucrat();
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	private:
		const std::string	name;
		int					grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
