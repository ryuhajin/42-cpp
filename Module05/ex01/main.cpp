#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    //sign grade
    try
    {
        Form a("Cake", 0, 30);
    }
    catch (const std::exception & e)
    {
        std::cout << "[Error] out of range : " << e.what() << '\n' << std::endl; 
    }

    try
    {
        Bureaucrat joy("Joy", 1);
        Bureaucrat amumu("Amumu", 150);
        Bureaucrat lulu("Lulu", 75);

        Form cakeform("Cake", 75, 75);

        // amumu.signForm(cakeform);
        // cakeform.beSigned(amumu);
    
        lulu.signForm(cakeform);
        cakeform.beSigned(lulu);
    
        joy.signForm(cakeform);
        cakeform.beSigned(joy);

        std::cout << cakeform;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n' << std::endl;
    }
    
    return (0);
}
