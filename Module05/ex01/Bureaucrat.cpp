#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(void)
    :_name("default"), _grade(150)
{
    std::cout << "[Constructor] Bureaucrat " << _name << " grade : " << _grade << std::endl;
}


Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
    :_name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
    
    this->_grade = grade;
    std::cout << "[Constructor] Bureaucrat " << _name << " grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    :_name(other.getName()), _grade(other.getGrade())
{
    std::cout << "[Copy Constructor] Bureaucrat " << _name << " grade : " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "[Destructor] Bureaucrat " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "[Copy Operator=] grade copy." << std::endl;
	this->_grade = other.getGrade();

    return (*this);
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &input)
{
    out << input.getName() << " bureaucrat grade " << input.getGrade() << std::endl;
    return (out);
}

const std::string& Bureaucrat::getName(void) const
{
    return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::gradeUp(void)
{
    if (getGrade() == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::gradeDown(void)
{
    if (getGrade() == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "too high grade";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "too low grade";
}

void Bureaucrat::signForm(Form& form) const
{
    if (form.getSignGrade() < this->getGrade())
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " form because ";
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        std::cout << this->getName() << " signed " << form.getName() << "Form" << std::endl;
    }
}
