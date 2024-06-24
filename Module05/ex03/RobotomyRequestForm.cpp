#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("default", 72, 45)
{
	std::cout << "[Constructor] Robotomy Form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:AForm(target, 72, 45)
{
	std::cout << "[Constructor] Robotomy Form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other)
{
	std::cout << "[Copy Constructor] Robotomy Form" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "[Copy Operator=] Robotomy Form" << std::endl;
	AForm::operator=(other);

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "[Destructor] Robotomy Form" << std::endl;
}

bool	RobotomyRequestForm::randomFiftyFifty(void) const
{
	srand(time(0));
	return (rand() % 2);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
	{
		std::cout << this->getName() << " Form Cannot be executed. because ";
		throw AForm::signedFalseException();
	}
	else if (this->getExecuteGrade() < executor.getGrade())
	{
		std::cout << executor.getName() << " Cannot be executed. because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "Bzzz...bzzz...." << std::endl;
		if (this->randomFiftyFifty())
			std::cout << "Congratulations. You've succeeded." << std::endl;
		else
			std::cout << "Sorry, that's a failure." << std::endl;
	}
}
