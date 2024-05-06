#ifndef	CONTACT_H
#define	CONTACT_H

# include <limits>
# include <cctype>
# include "Contact.h"

std::string& Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string& Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string& Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string& Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string& Contact::get_secret(void)
{
	return (this->secret);
}

std::string& Contact::input_check (std::string &input)
{
	while (!std::getline(std::cin, input))
	{
		std::cout << "Input error. Please enter again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return input;
}

bool Contact::digit_check (std::string &input)
{
	for(std::string::iterator i = input.begin(); i != input.end(); ++i)
	{
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

std::string& Contact::phonenumber_check (std::string &input)
{
	while (!std::getline(std::cin, input) && !digit_check(input))
	{
		std::cout << "Input error. Please enter again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}

Contact::Contact& Contact::add_contact(void)
{
	std::string str;
	std::cout << "Please enter a first name." << std::endl;
	Contact.get_first_name().input_check(str);

	std::cout << "Please enter a last name." << std::endl;
	Contact.get_last_name().input_check(str);

	std::cout << "Please enter a nickname." << std::endl;
	Contact.get_nickname().input_check(str);

	std::cout << "Please enter a phone number. (digit only)" << std::endl; //숫자만인지 체크

}

#endif