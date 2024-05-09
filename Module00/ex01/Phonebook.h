# ifndef	PHONEBOOK_H
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
	PhoneBook()
	{
		this->recent_add_idx = 0;
		this->total_add_count = 0;
	}

	std::string&	input_check(std::string &input);
	bool	digit_check(std::string &input);
	void	str_number_check(std::string &index);
	void	print_command(void);
	int		command_check (const std::string &input);
	void	default_pb_head(void);
	void	default_pb_line(int idx);
	void	lenth_check_print(std::string &string);
	void	pb_line (Contact &contact, int idx);
	void	print_phonebook(void);
	void	add_contact(Contact &contact);
	void	set_phonebook(void);
	void	print_info(int idx);
	bool	print_contact(void);
	bool	select_command (const std::string &input);

};

#endif
