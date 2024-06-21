# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form
{
private:
    const std::string _name;
    const unsigned int _signGrade;
    const unsigned int _executeGrade;
    bool _sign;

    Form();
public:
    Form(const std::string& name, const unsigned int signGrade, const unsigned int executeGrade);
    Form(const Form& other);
    ~Form();

    Form&   operator= (const Form& other);

    const std::string   getName(void) const;
    unsigned int        getSignGrade(void) const;
    unsigned int        getExecuteGrade(void) const;
    bool                getSign(void) const;
    void                beSigned(Bureaucrat &bureaucrat);

    //exception
    class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
    class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream &out, const Form &form);

#endif
