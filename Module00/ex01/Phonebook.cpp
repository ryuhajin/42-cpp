#include "Phonebook.h"

void	PhoneBook::print_phonebook ()
{
	int i;
	int j;

	if (this->total_add_count < 9)
		i = total_add_count;
	else
		i = 8;

	j = 0;
	default_pb_head();
	while (j < i)
	{
		pb_line(this->phonebook[j], j);
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

// 길이 10으로 정규화 시켜서 출력해주는 함수 : print_reg_10len
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
