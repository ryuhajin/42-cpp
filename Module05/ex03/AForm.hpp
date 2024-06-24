# ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    const unsigned int _signGrade;
    const unsigned int _executeGrade;
    bool _sign;

    AForm();
public:
    AForm(const std::string& name, const unsigned int signGrade, const unsigned int executeGrade);
    AForm(const AForm& other);
    virtual ~AForm();

    AForm&   operator= (const AForm& other);

    const std::string   getName(void) const;
    unsigned int        getSignGrade(void) const;
    unsigned int        getExecuteGrade(void) const;
    bool                getSign(void) const;
    
    void                beSigned(Bureaucrat &bureaucrat);
    virtual void        execute(Bureaucrat const & executor) const = 0;

    //exception
    class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

    class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class signedFalseException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class UnexpectedException : public std::exception {
	public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator << (std::ostream &out, const AForm &form);

#endif
