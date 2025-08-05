#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, false, "defaultTarget")
{
	std::cout << "ShrubberyCreationForm created successfully" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, false, target)
{
	std::cout << "ShrubberyCreationForm created successfully" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm created successfully" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
	}
	return *this;
}

void ShrubberyCreationForm::execute() const
{
	std::ofstream File(this->getTarget() + "_shrubbery");
	for (int i = 0; i < 4; i++)
		File << "       _-_\n    /~‘~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n _ -   | |   -_\n      // \\\\" << std::endl;
	File.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed successfully" << std::endl;
}
