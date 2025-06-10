#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat a(1);

		std::cout << "Bureaucrat grade is:" << a.getGrade() << std::endl;
		for (int i = 0; i < 10; i++)
		{
			a.decrementGrade();
		}
		std::cout << "Bureaucrat grade is:" << a.getGrade() << std::endl;
		for (int i = 0; i < 10; i++)
		{
			a.incrementGrade();
		}
		std::cout << "Bureaucrat grade is:" << a.getGrade() << std::endl;
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		try
		{
			Bureaucrat a(0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		try
		{
			Bureaucrat a(151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (SUCCESS);
}
