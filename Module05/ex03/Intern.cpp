#include "Intern.hpp"

#include <iostream>
#include <string>

Intern::Intern()
{
    std::cout << "[Constructor] Intern" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "[Copy Constructor] Intern" << std::endl;
    *this = other;
}

Intern& Intern::operator= (const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "[Destructor] Intern" << std::endl;
}

const char* Intern::UnexpectedException::what(void) const throw()
{
	return "\nNot in the correct format. makeForm fails!\n";
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    static Form createForm[3] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

	static std::string formNames[3] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "\nIntern creates " << formNames[i] << '\n' << std::endl;
			return (createForm[i](target));
		}
	}
	
	throw(Intern::UnexpectedException());
}
