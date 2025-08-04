#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat bureaucrat("Jhon", 3);
		Form	A("A423", 2, 5, false);
		Form	B("B030", 5, 10, false);
		Form	C("C666", 3, 40, false);

		bureaucrat.signForm(A);

	}
	return (SUCCESS);
}
