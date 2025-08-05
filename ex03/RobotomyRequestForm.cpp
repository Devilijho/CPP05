#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, false, "defaultTarget")
{
	std::cout << "RobotomyRequestForm created successfully" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, false, target)
{
	std::cout << "RobotomyRequestForm created successfully" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other)
{
	std::cout << "RobotomyRequestForm created successfully" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute() const
{
	srand(time(NULL));
	int rand = std::rand() % 2;
	std::cout << "*BZZZZZZZZZZZZZZZZZZZ*" << std::endl;
	if (rand == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized :(" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed successfully" << std::endl;
}
