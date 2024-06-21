#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <stdexcept>

int main(void)
{
	//Shrubbbery
    try
    {
		Bureaucrat zedd("Zedd", 150);
		Bureaucrat teemo("Teemo", 145);
		Bureaucrat yumi("Yumi", 137);
       	
		ShrubberyCreationForm sForm("Shrybbery");
		std::cout << '\n' << sForm << '\n';
	
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

	//Robotomy
	try
    {
		Bureaucrat zedd("Zedd", 150);
		Bureaucrat teemo("Teemo", 72);
		Bureaucrat yumi("Yumi", 45);
       	
		RobotomyRequestForm rForm("Robotomy");
		std::cout << '\n' << rForm << '\n';
	
		// zedd.signForm(rForm);
		// rForm.beSigned(zedd);
		// zedd.executeForm(rForm);
		// rForm.execute(zedd);

		// teemo.signForm(rForm);
		// rForm.beSigned(teemo);
		// teemo.executeForm(rForm);
		// rForm.execute(teemo);

		yumi.signForm(rForm);
		rForm.beSigned(yumi);
		yumi.executeForm(rForm);
		rForm.execute(yumi);
    }
    catch (const std::exception & e)
    {
        std::cout << "[Error] " << e.what() << '\n' << std::endl; 
    }

	//Pardon
	try
    {
		Bureaucrat zedd("Zedd", 150);
		Bureaucrat teemo("Teemo", 25);
		Bureaucrat yumi("Yumi", 5);
       	
		PresidentialPardonForm pForm("Sylas");
		std::cout << '\n' << pForm << '\n';
	
		// zedd.signForm(pForm);
		// pForm.beSigned(zedd);
		// zedd.executeForm(pForm);
		// pForm.execute(zedd);

		// teemo.signForm(pForm);
		// pForm.beSigned(teemo);
		// teemo.executeForm(pForm);
		// pForm.execute(teemo);

		yumi.signForm(pForm);
		pForm.beSigned(yumi);
		yumi.executeForm(pForm);
		pForm.execute(yumi);
    }
    catch (const std::exception & e)
    {
        std::cout << "[Error] " << e.what() << '\n' << std::endl; 
    }


    return (0);
}
