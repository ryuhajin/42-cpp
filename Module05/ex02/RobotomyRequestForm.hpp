#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	bool	randomFiftyFifty(void) const;
	void	execute(Bureaucrat const & executor) const;
};

#endif
