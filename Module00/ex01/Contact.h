#ifndef CONTACT_H
#define CONTACT_H

# include <iostream>
# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
public:
	Contact(/* args */);
	~Contact();

	std::string& Contact::get_first_name();
	std::string& Contact::get_last_name();
	std::string& Contact::get_nickname();
	std::string& Contact::get_phone_number();
	std::string& Contact::get_secret();
};

Contact::Contact()
{
}

Contact::~Contact()
{
}
#endif
