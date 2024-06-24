#include "Intern.hpp"

#include <iostream>
#include <string>

Intern::Intern()
{
    std::cout << "[]" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "[]" << std::endl;
    *this = other;
}

Intern& Intern::operator= (const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "[]" << std::endl;
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

AForm* Intern::makeForm(const std::string& form, const std::string& target) const
{
    f_Ptr form[3] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
}