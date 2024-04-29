# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.h"

class PhoneBook
{
private:
	static const int Max_contact = 8;
	Contact::phonebook[Max_contact];
	int	recent_add_idx;
	int total_add_count;
public:
	PhoneBook(/* args */);
	~PhoneBook();
};

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}
