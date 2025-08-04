#pragma once

#include <string>
#include <ostream>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute, bool isSigned);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	int			getGradeToSign() const;
	int			getgradeToExecute() const;
	bool		getSign() const;
	void		beSigned(Bureaucrat &bureaucrat);

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
	const int			gradeToSign;
	const int			gradeToExecute;
	bool				isSigned;

};

std::ostream &operator<<(std::ostream &out, const Form &form);
