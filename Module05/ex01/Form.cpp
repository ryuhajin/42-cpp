#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

Form::Form(void)
    :_name("default"), _signGrade(150), _executeGrade(150), _sign(false)
{
    std::cout << "[Constructor] Form" << std::endl;
}

Form::Form(const std::string& name, const unsigned int signGrade, const unsigned int executeGrade)
    :_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _sign(false)
{
    std::cout << "[Constructor] Form" << std::endl;

    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}
Form::Form(const Form& other)
    :_name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()), _sign(false)
{
    std::cout << "[Copy Constructor] Form" << std::endl;
}

Form::~Form()
{
    // std::cout << "[Destructor] Form" << std::endl;
}

//operator
Form& Form::operator= (const Form& other)
{
    std::cout << "[Copy Operator=] Form" << std::endl;
    (void)other;

    return (*this);
}

std::ostream& operator << (std::ostream &out, const Form &form)
{
    out << "[Form]\n" << "Name: " << form.getName() << "\n"
    << "Sign grade: " << form.getSignGrade() << "\n"
    << "Execute grade: " << form.getExecuteGrade() << "\n"
    << "Sign: " << form.getSign() << std::endl;

    return (out);
}

//get func
const std::string Form::getName(void) const
{
    return (this->_name);
}
unsigned int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

unsigned int Form::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

bool Form::getSign(void) const
{
    return (this->_sign);
}

//exception
const char* Form::GradeTooHighException::what(void) const throw()
{
	return "too high grade";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "too low grade";
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if(this->_signGrade < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    else
        _sign = true;
}
