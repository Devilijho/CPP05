#pragma once

#include <string>
#include <ostream>
#include <iostream>

class Bureaucrat;

class AForm
{
	public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute, bool isSigned);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	std::string getName() const;
	int			getGradeToSign() const;
	int			getgradeToExecute() const;
	bool		getSign() const;
	void		beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const;

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

std::ostream &operator<<(std::ostream &out, const AForm &form);
