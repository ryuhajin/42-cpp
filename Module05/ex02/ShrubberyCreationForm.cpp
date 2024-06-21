#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm("default", 145, 137)
{
	std::cout << "[Constructor] Shrubbery Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:AForm(target, 145, 137)
{
	std::cout << "[Constructor] Shrubbery Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other)
{
	std::cout << "[Copy Constructor] Shrubbery Form" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "[Copy Operator=] Shrubbery Form" << std::endl;
	AForm::operator=(other);

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "[Destructor] Shrubbery Form" << std::endl;
}

bool	ShrubberyCreationForm::makeTreeFile(void) const
{
	std::ofstream file;
	file.open("ShrubberyTree", std::ios::out | std::ios::trunc);

	if (!file)
	{
        std::cerr << "Unable to open the file. ";
        return (false);
    }
	else
	{
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠈⣷⠻⠛⣦⠴⠶⠤⣤⠞⠉⠀⠀⠀⠙⢳⡄⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠾⢧⠀⠀⠀⠀⠀⠀⢸⣁⠀⠀⠀⠈⠳⠀⠀⠀⠀⠀⣨⡷⠶⢤⡀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠚⠛⠓⠾⣄⠀⠀⢀⡴⠚⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⢼⡁⠀⠀⠀⠀⠀⠚⠉⠉⠛⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠾⠧⣄⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⣠⡴⠛⠉⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣧⡄⠀\n";
    	file << "⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠤⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠃⠀\n";
    	file << "⠀⠀⠀⠀⢰⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠈⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠚⢧⡀⠀⠀\n";
    	file << "⠀⢀⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡧⠀⠀\n";
    	file << "⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠢⠖⠚⣧⠀⠀⠀⠀⠀⠀⠀⠰⣤⣤⣤⡞⠁⠀⠀\n";
    	file << "⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠰⣦⣀⡀⢀⣠⠏⠀⠀⠀⠐⠶⠤⠴⠚⠁⠠⠿⠧⢤⡀⠀\n";
    	file << "⠙⣆⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⠚⠻⡄⠉⣽⣄⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠆\n";
    	file << "⠀⢘⡷⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡗⢶⡏⠀⠀⠙⠶⠋⠈⠁⡞⢿⣀⠀⣀⠀⠀⠀⠀⠀⠀⠴⠴⣟⡁\n";
    	file << "⠀⢺⡀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⣤⣴⢿⣧⡀⢳⡀⠀⠀⠀⠀⠀⢰⠇⠀⣿⣿⣥⣠⣄⡀⠀⢀⠀⠀⠀⣽⡇\n";
    	file << "⠀⠀⠙⠦⠤⢾⠀⠀⠀⠀⣀⠀⠀⠀⠀⣻⣦⡿⠙⠛⠃⠀⠀⠀⠀⠀⣼⠀⣼⣯⡿⠛⠉⠿⠤⡤⠟⢣⡤⠿⠋⠁\n";
    	file << "⠀⠀⠀⠀⠀⠘⢦⣀⣀⣀⡼⠓⠒⠒⠚⠁⠈⠳⡄⠀⠀⠀⠀⠀⠀⢀⣿⣾⣿⠻⣄⣀⢀⡼⠦⣄⣀⣰⠇⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⢸⣿⣰⠃⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠈⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢳⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠈⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠛⠓⠒⠒⠒⠒⠶⣤⣀⠀⠀⢶⣤⣀⣀⣀⣉⣙⣲⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⠾⡇⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀\n";
    	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣢⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	}

	file.close();
	return (true);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
	{
		std::cout << this->getName() << " Form Cannot be executed. because ";
		throw AForm::signedFalseException();
	}
	else if (this->getExecuteGrade() < executor.getGrade())
	{
		std::cout << executor.getName() << " Cannot be executed. because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		if (this->makeTreeFile() == false)
			throw AForm::UnexpectedException();
	}
}
