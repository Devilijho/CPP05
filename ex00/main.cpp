#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat a("a",1);

		std::cout << "Bureaucrat grade is: " << a.getGrade() << std::endl;
		for (int i = 0; i < 10; i++) a.decrementGrade();
		std::cout << "Bureaucrat grade is: " << a.getGrade() << std::endl;
		for (int i = 0; i < 10; i++) a.incrementGrade();
		std::cout << "Bureaucrat grade is: " << a.getGrade() << std::endl;
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		try
		{
			Bureaucrat a("a",0);
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
			Bureaucrat a("a",151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "TEST OPERATOR << OVERLOAD" << std::endl;
		Bureaucrat a("a",3);
		std::cout << a;
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "TEST INSTANCE ERROR" << std::endl;
		Bureaucrat b("b",151);
	}
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "TEST INSTANCE ERROR" << std::endl;
		Bureaucrat c("c",0);
	return (SUCCESS);
	}
}
