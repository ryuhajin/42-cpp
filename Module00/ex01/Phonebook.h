#ifndef	PHONEBOOK_H
#define	PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>

# include "Contact.h"

class PhoneBook
{
private:
	static const int Max_contact = 8;
	Contact phonebook[Max_contact];
	int	recent_add_idx;
	int total_add_count;
public:
	PhoneBook();
	~PhoneBook();
	void	PhoneBook::print_phonebook();
	void	PhoneBook::default_pb_head(void);
	void	PhoneBook::default_pb_line(int i);
	void	PhoneBook::lenth_check_print(std::string &string);
	void	PhoneBook::pb_line (Contact &contact, int i);
};

PhoneBook::PhoneBook()
{
	this->recent_add_idx = 0;
	this->total_add_count = 0;
}

PhoneBook::~PhoneBook()
{
}

#endif
