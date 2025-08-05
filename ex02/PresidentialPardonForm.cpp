#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, false, "defaultTarget")
{
	std::cout << "PresidentialPardonForm created successfully" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, false, target)
{
	std::cout << "PresidentialPardonForm created successfully" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other)
{
	std::cout << "PresidentialPardonForm created successfully" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::execute() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed successfully" << std::endl;
}
