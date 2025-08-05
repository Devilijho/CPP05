#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		PresidentialPardonForm formA("Nacho");
		Bureaucrat p1("Pablo", 1);

		p1.signForm(formA);
		p1.executeForm(formA);
	}
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		RobotomyRequestForm formA("Nacho");
		Bureaucrat p1("Pablo", 1);

		p1.signForm(formA);
		p1.executeForm(formA);
	}
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		ShrubberyCreationForm formA("Nacho");
		Bureaucrat p1("Pablo", 1);

		p1.signForm(formA);
		p1.executeForm(formA);
	}
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		PresidentialPardonForm formA("Nicolas");
		Bureaucrat p1("Juan", 20);

		p1.signForm(formA);
		p1.executeForm(formA);
	}
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		PresidentialPardonForm formA("Sebastian");
		Bureaucrat p1("Santiago", 30);

		p1.executeForm(formA);
	}
	return (SUCCESS);
}
