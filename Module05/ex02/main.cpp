#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <stdexcept>

int main(void)
{
    try
    {
		Bureaucrat zedd("Zedd", 150);
		Bureaucrat teemo("Teemo", 145);
		Bureaucrat yumi("Yumi", 137);
       	
		ShrubberyCreationForm sForm("LOL");
		std::cout << '\n' << sForm;
	
		// zedd.signForm(sForm);
		// sForm.beSigned(zedd);
		// zedd.executeForm(sForm);
		// sForm.execute(zedd);

		// teemo.signForm(sForm);
		// sForm.beSigned(teemo);
		// teemo.executeForm(sForm);
		// sForm.execute(teemo);

		yumi.signForm(sForm);
		sForm.beSigned(yumi);
		yumi.executeForm(sForm);
		sForm.execute(yumi);
    }
    catch (const std::exception & e)
    {
        std::cout << "[Error] " << e.what() << '\n' << std::endl; 
    }

    return (0);
}
