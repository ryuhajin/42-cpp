#ifndef	PHONEBOOK_H
#define	PHONEBOOK_H

#include "Contact.h"
#include <string>


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

	void	PhoneBook::print_command (void);
	int		PhoneBook::command_check (const std::string &input);
	void	PhoneBook::print_phonebook(void);
	void	PhoneBook::default_pb_head(void);
	void	PhoneBook::default_pb_line(int i);
	void	PhoneBook::lenth_check_print(std::string &string);
	void	PhoneBook::pb_line (Contact &contact, int idx);
	void	PhoneBook::print_phonebook(void);
	void	PhoneBook::set_phonebook(void);
	void	PhoneBook::print_info(int i);
	bool	PhoneBook::print_contact (void);
	bool	PhoneBook::select_command (const std::string &input);
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
