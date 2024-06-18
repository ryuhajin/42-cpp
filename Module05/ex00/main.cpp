#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    //constructor case
    try
    {
        Bureaucrat joy("Joy", 0);
    }
    catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
	}

    try
    {
        Bureaucrat joy("Joy", 151);
    }
	catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
	}

    //grade function case
    try
    {
        Bureaucrat joy("Joy", 1);
        joy.gradeUp();
    }
	catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
	}

    try
    {
        Bureaucrat amumu("Amumu", 150);
        amumu.gradeDown();
    }
	catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
	}

    //good case
    try
    {
        Bureaucrat lulu("lulu", 30);
        lulu.gradeUp();
        std::cout << lulu;

        lulu.gradeDown();
        std::cout << lulu;
    }
	catch (const Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
	}
    
    return (0);
}
