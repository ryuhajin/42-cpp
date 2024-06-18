#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& in_name, const unsigned int in_grade)
    :name(in_name)
{
    if (in_grade < 1 || in_grade > 150)
        throw std::out_of_range("Grade must be 1 ~ 150");
    
    grade = in_grade;
    std::cout << "[Constructor] Bureaucrat " << name << " grade : " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& in)
    :name(in.name), grade(in.grade)
{
    std::cout << "[Copy Constructor] Bureaucrat " << name << " grade : " << grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Destructor] Bureaucrat " << name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& in)
{
    std::cout << "[Copy Operator=] grade copy." << std::endl;
    grade = in.grade;

    return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
    return (name);
}

unsigned int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void Bureaucrat::gradeUp(void)
{
    if (getGrade() == 1)
        throw std::out_of_range("too high grade");
    grade--;
}

void Bureaucrat::gradeDown(void)
{
    if (getGrade() == 150)
        throw std::out_of_range("too low grade");
    grade++;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &input)
{
    out << input.getName() << " bureaucrat grade " << input.getGrade() << std::endl;
    return (out);
}
