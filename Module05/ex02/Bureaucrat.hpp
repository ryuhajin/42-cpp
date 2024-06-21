#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    unsigned int _grade;

    Bureaucrat();
public:
    Bureaucrat(const std::string& name, const unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName(void) const;
    unsigned int getGrade(void) const;
    void gradeUp(void);
    void gradeDown(void);

    void signForm(AForm &form) const;
    void executeForm(AForm const &form) const;

	// exception
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &input);

#endif