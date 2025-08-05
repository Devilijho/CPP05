#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <memory>
#include <new>

AForm *form1(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	if (!form)
		throw std::bad_alloc();
	return form;
}

AForm *form2(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	if (!form)
		throw std::bad_alloc();
	return form;
}

AForm *form3(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	if (!form)
		throw std::bad_alloc();
	return form;
}

Intern::Intern()
{
	std::cout << "Random intern appears" << std::endl;
	formNames[0] = "presidential pardon";
	formNames[1] = "robotomy request";
	formNames[2] = "shrubbery creation";
	formFuncs[0] = form1;
	formFuncs[1] = form2;
	formFuncs[2] = form3;
}

Intern::Intern(const Intern &other)
{
	for (int i = 0; i < 3; i++)
	{
		formNames[i] = other.formNames[i];
		formFuncs[i] = other.formFuncs[i];
	}
	std::cout << "Random intern appears" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Random intern dissappears" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *form;

	form = nullptr;
	for (int i = 0; i < 3; i++)
		if (this->formNames[i] == name)
			form = this->formFuncs[i](target);
	if (form == nullptr)
	{
		std::cout << "Intern couldn't create form :";
		throw std::bad_exception();
	}
	return (form);
}
