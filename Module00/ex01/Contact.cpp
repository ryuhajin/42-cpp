#ifndef	CONTACT_H
#define	CONTACT_H

# include "Phonebook.h"

void print_str(const std::string &str)
{
	std::cout << str << std::endl;
}

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

void set_first_name(const std::string& input)
{
	first_name = input;
}
void set_last_name(const std::string& input)
{
	last_name = input;
}
void set_nickname(const std::string& input)
{
	nickname = input;
}
void set_phone_number(const std::string& input)
{
	phone_number = input;
}
void set_secret(const std::string& input)
{
	secret = input;
}

std::string& Contact::input_check (std::string &input)
{
	while (!std::getline(std::cin, input))
	{
		print_str("Input error. Please enter again.");
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
		{
			print_str("Input error. Please enter again.");
			return false;
		}
	}
	return true;
}

void Contact::add_contact(Contact::Contact& contact)
{
	print_str("Please enter a first name.");
	std::string fn;
	set_first_name(input_check(fn));

	print_str("Please enter a last name.");
	std::string ln;
	set_last_name(input_check(ln));

	print_str("Please enter a nickname.");
	std::string nn;
	set_nickname(input_check(nn));

	print_str("Please enter a phone number. (digit only)");
	std::string pn;
	input_check(pn);
	while (!digit_check(pn))
		input_check(pn);
	set_phonenumber(pn);

	print_str("Please enter a secret.");
	std::string sr;
	set_secret(input_check(sr));
}

#endif