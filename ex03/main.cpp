#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		Intern someRandomIntern;
		Bureaucrat someRandomBureaucrat("Pablo", 1);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		someRandomBureaucrat.signForm(*rrf);
		someRandomBureaucrat.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << "---------------------------------------------------------" << std::endl;
		Intern someRandomIntern;
		Bureaucrat someRandomBureaucrat("Pablo", 1);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "nacho");
		someRandomBureaucrat.signForm(*rrf);
		someRandomBureaucrat.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << "---------------------------------------------------------" << std::endl;
		Intern someRandomIntern;
		Bureaucrat someRandomBureaucrat("Pablo", 1);
		AForm* rrf;
		(void)rrf;
		try
		{
			rrf = someRandomIntern.makeForm("bla bla bla ble ble ble blu blu blu", "Bender");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (SUCCESS);
}
