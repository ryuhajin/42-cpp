#include "Phonebook.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>

PhoneBook::PhoneBook()
	: recent_add_idx(0)
	, total_add_count(0)
{}

PhoneBook::~PhoneBook()
{}

std::string&	PhoneBook::input_check(std::string &input)
{

	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "-> EOF(End Of File). Exit the phonebook.\n" << std::endl;
				std::cin.clear();
				clearerr(stdin);
				exit(0);
			}
			else
			{
				std::cout << "-> Input error. Please enter again.\n" << std::endl;
				std::cin.clear();
				clearerr(stdin);
				continue;
			}
		}
		else
			break;
	}

	return (input);
}

bool	PhoneBook::digit_check(std::string &input)
{
	for(std::string::iterator i = input.begin(); i != input.end(); ++i)
	{
		if (!std::isdigit(*i))
		{
			std::cout << "-> Input error. Please enter again.\n" << std::endl;
			return (false);
		}
	}
	return (true);
}

void	PhoneBook::str_number_check(std::string &index)
{
	input_check(index);
	while (!(digit_check(index)))
		input_check(index);
}

void	PhoneBook::print_command(void)
{
	std::cout << "=== Hello. Enter the command of your choice. ===" << std::endl;
	std::cout << "# ADD" << std::endl;
	std::cout << "# SEARCH" << std::endl;
	std::cout << "# EXIT" << std::endl;
}

int		PhoneBook::command_check(const std::string &input)
{
	static const std::string add = "ADD";
	static const std::string search = "SEARCH";
	static const std::string exit = "EXIT";

	return (input == add || input == search || input == exit);
}

void	PhoneBook::default_pb_head(void)
{
	std::cout << "|";
	std::cout << std::setw(10) <<  "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
}
void	PhoneBook::default_pb_line(int idx)
{
	std::cout << "|" ;
	std::cout << std::setw(10) << idx << "|";
	std::cout << std::setw(10) << " " << "|";
	std::cout << std::setw(10) << " " << "|";
	std::cout << std::setw(10) << " " << "|";
	std::cout << std::endl;
}

void	PhoneBook::lenth_check_print(std::string &string)
{
	static const int max_len = 10;
	
	std::string add_string = string.substr(0, 9) + ".";

	if (string.size() >= max_len)
		std::cout << std::setw(10) << add_string <<  "|";
	else
		std::cout << std::setw(10) << string << "|";
}

void	PhoneBook::pb_line(Contact &contact, int idx)
{
	std::cout << "|";
	std::cout << std::setw(10) << idx << "|";
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

void	PhoneBook::add_contact(Contact &contact)
{
	std::cout << "Please enter a first name." << std::endl;
	std::string fn;
	contact.set_first_name(input_check(fn));

	std::cout << "Please enter a last name." << std::endl;
	std::string ln;
	contact.set_last_name(input_check(ln));

	std::cout << "Please enter a nickname." << std::endl;
	std::string nn;
	contact.set_nickname(input_check(nn));

	std::cout << "Please enter a phone number. (digit only)" << std::endl;
	std::string pn;
	str_number_check(pn);
	contact.set_phone_number(pn);

	std::cout << "Please enter a secret." << std::endl;
	std::string sr;
	contact.set_secret(input_check(sr));
}

void	PhoneBook::set_phonebook(void)
{
	if (total_add_count < 8)
	{
		recent_add_idx = total_add_count;
		add_contact(phonebook[recent_add_idx]);
		total_add_count++;
	}
	else
	{
		if(recent_add_idx == 7)
			recent_add_idx = 0;
		add_contact(phonebook[recent_add_idx]);
		recent_add_idx++;
		total_add_count++;
	}
}

void PhoneBook::print_info(int idx)
{
	std::cout << "===============================================" << std::endl;
	std::cout << "First name: "<< phonebook[idx].get_first_name() << std::endl;
	std::cout << "Last name: "<< phonebook[idx].get_last_name() << std::endl;
	std::cout << "Nickname: "<< phonebook[idx].get_nickname() << std::endl;
	std::cout << "Phone number: "<< phonebook[idx].get_phone_number() << std::endl;
	std::cout << "Secret: "<< phonebook[idx].get_secret() << std::endl;
	std::cout << "===============================================" << std::endl;
}

bool	PhoneBook::print_contact(void)
{
	std::string	index;
	
	str_number_check(index);
	std::stringstream i(index);
	int num;
	i >> num;

	if (num < 0 || num > 7)
	{
		std::cout <<  "-> index error : Not a valid index number.\n" << std::endl;
		return (false);
	}
	else if (num >= total_add_count)
	{
		std::cout << "-> index error : An empty index.\n" << std::endl;
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
		std::cout << "Please enter the index you want to see. (0-7 only)" << std::endl;
		return (print_contact());
	}
	else
	{
		std::cout << "-> Exit the phonebook." << std::endl;
		exit(0);
	}
}
