#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("default", 25, 5)
{
	std::cout << "[Constructor] Presidential Form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:AForm(target, 25, 5)
{
	std::cout << "[Constructor] Presidential Form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other)
{
	std::cout << "[Copy Constructor] Presidential Form" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "[Copy Operator=] Presidential Form" << std::endl;
	AForm::operator=(other);

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "[Destructor] Presidential Form" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
		std::cout << this->getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
