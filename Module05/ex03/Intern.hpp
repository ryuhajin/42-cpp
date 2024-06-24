# ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <stdexcept>

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern&   operator= (const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target) const;

	class UnexpectedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);
};

typedef AForm* (*Form)(const std::string&);

#endif