# ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern&   operator= (const Intern& other);

    AForm* makeForm(const std::string& form, const std::string& target) const;

private:
    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);
};

typedef AForm* (*f_Ptr)(const std::string&);

#endif