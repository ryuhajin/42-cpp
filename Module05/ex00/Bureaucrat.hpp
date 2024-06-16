#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    const std::string name;
    unsigned int grade;

    Bureaucrat();
public:
    Bureaucrat(const std::string& name);
    ~Bureaucrat();

    const std::string getName(void) const;
    unsigned int getGrade(void) const;

    void gradeUp(unsigned int num);
    void gradeDown(unsigned int num);
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &input);

#endif