#include "Contact.h"
#include <string>

std::string&	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string&	Contact::get_last_name(void)
{
	return (last_name);
}

std::string&	Contact::get_nickname(void)
{
	return (nickname);
}

std::string&	Contact::get_phone_number(void)
{
	return (phone_number);
}

std::string&	Contact::get_secret(void)
{
	return (secret);
}

void	Contact::set_first_name(const std::string& input)
{
	first_name = input;
}
void	Contact::set_last_name(const std::string& input)
{
	last_name = input;
}
void	Contact::set_nickname(const std::string& input)
{
	nickname = input;
}
void	Contact::set_phone_number(const std::string& input)
{
	phone_number = input;
}
void	Contact::set_secret(const std::string& input)
{
	secret = input;
}
