#include "Phonebook.h"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook p;

	while (true)
	{
		p.print_command();
		std::string input;
		p.input_check(input);
		if (p.command_check(input) == false)
		{	
			std::cout << "-> Command error. Please enter again.\n" << std::endl;
			continue;
		}
		else
			p.select_command(input);
	}
	return (0);
}
