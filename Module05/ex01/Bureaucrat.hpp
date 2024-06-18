#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
class Bureaucrat
{
private:
    const std::string name;
    unsigned int grade;

    Bureaucrat();
public:
    Bureaucrat(const std::string& in_name, const unsigned int in_grade);
    Bureaucrat(const Bureaucrat& in);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& in);

    const std::string& getName(void) const;
    unsigned int getGrade(void) const;
    void gradeUp(void);
    void gradeDown(void);
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &input);

#endif