# include "Phonebook.h"

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
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}
