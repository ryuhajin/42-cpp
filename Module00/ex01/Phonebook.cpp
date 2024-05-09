#include "Phonebook.h"
#include <iostream>
#include <iomanip>
# include <sstream>

void	PhoneBook::print_command (void)
{
	std::cout << "Hello. Enter the command of your choice." << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << std::endl;
}

int		PhoneBook::command_check (const std::string &input)
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

void	PhoneBook::default_pb_head(void)
{
	std::cout << '|';
	std::cout << std::setw(10) << std::right <<  "index" << '|'
		<< std::setw(10) << std::right << "first name" << '|'
		<< std::setw(10) << std::right << "last name" << '|'
		<< std::setw(10) << std::right << "nickname" << '|' << std::endl;
}
void	PhoneBook::default_pb_line(int idx)
{
	std::cout << '|' ;
	std::cout << std::setw(10) << idx << '|';
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

void	PhoneBook::pb_line (Contact &contact, int idx)
{
	std::cout << '|';
	std::cout << std::setw(10) << idx << '|';
	lenth_check_print(contact.get_first_name());
	lenth_check_print(contact.get_last_name());
	lenth_check_print(contact.get_nickname());
	std::cout << std::endl;
}

void	PhoneBook::print_phonebook(void)
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

void	PhoneBook::set_phonebook(void)
{
	if (total_add_count < 8)
	{
		recent_add_idx = total_add_count;
		phonebook[recent_add_idx].add_contact();
		total_add_count++;
	}
	else
	{
		if(recent_add_idx == 7)
			recent_add_idx = 0;
		phonebook[recent_add_idx].add_contact();
		recent_add_idx++;
		total_add_count++;
	}
}

void PhoneBook::print_info(int idx)
{
	std::cout << "First name: "<< phonebook[idx].Contact::get_first_name() << std::endl;
	std::cout << "Last name: "<< phonebook[idx].Contact::get_last_name() << std::endl;
	std::cout << "Nickname: "<< phonebook[idx].Contact::get_nickname() << std::endl;
	std::cout << "Phone number: "<< phonebook[idx].Contact::get_phone_number() << std::endl;
	std::cout << "Secret: "<< phonebook[idx].Contact::get_secret() << std::endl;
}

bool	PhoneBook::print_contact(void)
{
	std::string	index;
	
	Contact::str_to_number(index);
	std::stringstream i(index);
	int num;
	i >> num;

	if (num < 0 || num > 7)
	{
		Contact::print_str("Not a valid index number.");
		return (false);
	}
	else
		print_info(num);
	return (true);
}

bool	PhoneBook::select_command (const std::string &input)
{
	if (input[0] == 'A')
	{
		set_phonebook();
		return (true);
	}
	else if(input[0] == 'S')
	{
		print_phonebook();
		Contact::print_str("Please enter the index you want to see.");
		return (print_contact());
	}
	else
	{
		std::cout << " Exit the phonebook." << std::endl;
		exit(0);
	}
}
