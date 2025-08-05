#pragma once

#include <string>
#include <iostream>
#include <array>
#include "AForm.hpp"

AForm *form1(std::string target);
AForm *form2(std::string target);
AForm *form3(std::string target);

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);
		AForm *makeForm(std::string name, std::string target);
	private:
		std::string formNames[3];
		AForm *(*formFuncs[3])(std::string target);
};
