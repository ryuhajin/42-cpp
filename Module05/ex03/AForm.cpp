#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

AForm::AForm(void)
    :_name("default"), _signGrade(150), _executeGrade(150), _sign(false)
{
    std::cout << "[Constructor] AForm" << std::endl;
}

AForm::AForm(const std::string& name, const unsigned int signGrade, const unsigned int executeGrade)
    :_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _sign(false)
{
    std::cout << "[Constructor] AForm" << std::endl;

    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& other)
    :_name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()), _sign(false)
{
    std::cout << "[Copy Constructor] AForm" << std::endl;
}

AForm::~AForm()
{
    // std::cout << "[Destructor] AForm" << std::endl;
}

//operator
AForm& AForm::operator= (const AForm& other)
{
    std::cout << "[Copy Operator=] AForm" << std::endl;
    (void)other;

    return (*this);
}

std::ostream& operator << (std::ostream &out, const AForm &form)
{
    out << "[Form]\n" << "Name: " << form.getName() << "\n"
    << "Sign grade: " << form.getSignGrade() << "\n"
    << "Execute grade: " << form.getExecuteGrade() << "\n"
    << "Sign: " << form.getSign() << std::endl;

    return (out);
}

//get func
const std::string AForm::getName(void) const
{
    return (this->_name);
}
unsigned int AForm::getSignGrade(void) const
{
    return (this->_signGrade);
}

unsigned int AForm::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

bool AForm::getSign(void) const
{
    return (this->_sign);
}

//exception
const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "too high grade";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "too low grade";
}

const char* AForm::signedFalseException::what(void) const throw()
{
	return "Not signed.";
}

const char* AForm::UnexpectedException::what(void) const throw()
{
	return "Unexpected exception.";
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(this->_signGrade < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    else
        _sign = true;
}
