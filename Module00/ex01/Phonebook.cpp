#include "Phonebook.h"

void	PhoneBook::print_command ()
{
	std::cout << "Hello. Enter the command of your choice." << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << std::endl;
}

bool	PhoneBook::command_check (const std::string &input)
{
	static std::string add = "ADD";
	static std::string search = "SEARCH";
	static std::string exit = "EXIT";

	if (input[0] == 'A')
		return (input.compare(add));
	else if (input[0] == 'S')
		return	(input.compare(search));
	return	(input.compare(exit));
}

void	PhoneBook::print_phonebook ()
{
	int i;
	int j;

	if (total_add_count < 8)
		i = total_add_count;
	else
		i = 8;

	j = 0;
	default_pb_head();
	while (j < i)
	{
		pb_line(this->phonebook[j], j);
		j++;
	}
	while (j < 8)
	{
		default_pb_line(j);
		j++;
	}
}

void	PhoneBook::default_pb_head(void)
{
	std::cout << '|';
	std::cout << std::setw(10) << std::right <<  "index" << '|'
		<< std::setw(10) << std::right << "first name" << '|'
		<< std::setw(10) << std::right << "last name" << '|'
		<< std::setw(10) << std::right << "nickname" << '|' << std::endl;
}
void	PhoneBook::default_pb_line(int i)
{
	std::cout << '|' ;
	std::cout << std::setw(10) << i << '|';
	std::cout << std::setw(10) << std::right <<  '|'
			<< std::setw(10) << std::right <<  '|'
			<< std::setw(10) << std::right <<  '|' << std::endl;
}

void	PhoneBook::lenth_check_print(std::string &string)
{
	static const int max_len = 10;
	
	if (string.size() >= max_len)
		std::cout<< std::setw(10) << std::right << string.substr(0, 9) << '.' <<  '|';
	else
		std::cout << std::setw(10) << std::right << string << '|';
}

void	PhoneBook::pb_line (Contact &contact, int i)
{
	std::cout << '|';
	std::cout << std::setw(10) << i << '|';
	lenth_check_print(contact.get_first_name());
	lenth_check_print(contact.get_last_name());
	lenth_check_print(contact.get_nickname());
	std::cout << std::endl;
}

void	PhoneBook::set_phonebook(void)
{
	if (total_add_count < 8)
	{
		recent_add_idx = total_add_count;
		Contact::add_contact(phonebook[recent_add_idx]);
		total_add_count++;
	}
	else
	{
		if(recent_add_idx == 7)
			recent_add_idx = 0;
		Contact::add_contact(PhoneBook[recent_add_idx]);
		recent_add_idx++;
		total_add_count++;
	}
}

bool	PhoneBook::select_command (const std::string &input)
{
	if (command_check(input) == -1)
	{
		std::cout << "Command error. Please enter again" << std::endl;
		return (false);
	}
	else if (input[0] == 'A')
	{
		set_phonebook();
		return (true);
	}
	else if(input[0] == 'S')
	{
		print_phonebook();
		Contact::print_str("Please enter the index you want to see.");
		//인덱스 번호 받기
		//한줄씩 정보 출력하기
	}
	else
	{
		std::cout << " Exit the phonebook." << std::endl;
		exit(0);
	}
}
