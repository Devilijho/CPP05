#pragma once

#define SUCCESS 0
#define ERROR 1

#include <string>
#include <iostream>

class Bureaucrat : public std::exception
{
	public:
		Bureaucrat(int grade);
		const char* what() const throw();
		int getGrade();
		std::string getName();
		void incrementGrade();
		void decrementGrade();
		virtual ~Bureaucrat() throw();


	private:
		const std::string	name;
		int					grade;

};
