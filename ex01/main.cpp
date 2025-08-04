#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat bureaucrat("Jhon", 3);
		Form	A("A423", 2, 5, false);

		bureaucrat.signForm(A);
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		Bureaucrat bureaucrat("Jhon", 3);
		Form	B("B030", 5, 10, false);

		bureaucrat.signForm(B);
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		Bureaucrat bureaucrat("Jhonny", 3);
		Form	C("C666", 3, 40, false);

		bureaucrat.signForm(C);
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		try
		{
			Form D("wao", 0, 2, false);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		try
		{
			Form D("wao", 160, 2, false);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		try
		{
			Form D("wao", 75, 0, false);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		try
		{
			Form D("wao", 10, 160, false);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (SUCCESS);
}
