#pragma once

#define SUCCESS 0
#define ERROR 1

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(int grade);
		int getGrade();
		std::string getName();
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
