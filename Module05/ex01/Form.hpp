# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form
{
private:
    const std::string name;
    const unsigned int signGrade;
    const unsigned int executeGrade;
    bool sign;

     ~Form();
public:
    Form(const std::string& in_name, const unsigned int num1, const unsigned int num2);

};

std::ostream& operator << (std::ostream &out, const Form &input);

#endif
