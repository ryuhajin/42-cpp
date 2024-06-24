#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <stdexcept>

int main(void)
{
	Intern intern;

    try
	{
		Bureaucrat lulu("lulu", 1);

        AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
        std::cout << "Created form: " << shrubberyForm->getName() << std::endl;
		
		lulu.signForm(*shrubberyForm);
		shrubberyForm->beSigned(lulu);
        lulu.executeForm(*shrubberyForm);
		shrubberyForm->execute(lulu);

		delete shrubberyForm;

        AForm* robotomyForm = intern.makeForm("robotomy request", "Robot");
        std::cout << "Created form: " << robotomyForm->getName() << std::endl;
        
		lulu.signForm(*robotomyForm);
		robotomyForm->beSigned(lulu);
        lulu.executeForm(*robotomyForm);
		robotomyForm->execute(lulu);
		
		delete robotomyForm;

        AForm* presidentialForm = intern.makeForm("presidential pardon", "Citizen");
        std::cout << "Created form: " << presidentialForm->getName() << std::endl;
        
		lulu.signForm(*presidentialForm);
		presidentialForm->beSigned(lulu);
        lulu.executeForm(*presidentialForm);
		presidentialForm->execute(lulu);
		delete presidentialForm;

		AForm* worngForm = intern.makeForm("Wrong form", "Wrong form");
		delete worngForm;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
