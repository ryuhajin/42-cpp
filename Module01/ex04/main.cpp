#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

std::string make_replace_filename(const char *filename)
{
	std::string file_name = filename;
	std::string rp(".replace");
	std::string new_filename = file_name + rp;

	return (new_filename);
}

void replace_str (std::ifstream &original, std::ofstream &replace_file, char *s1, char *s2)
{
	std::string str;
	size_t s1_len = strlen(s1);
	size_t s2_len = strlen(s2);
	size_t idx = 0;

	while (original)
	{
		//while getline
		//while (if idx != npos) 문자열 하나에 replace word가 여러개 들어있을 경우가 있어서 while 문 써야함
		std::getline(original, str);
		std::cout << "getline: " << str << std::endl;
		idx = str.find(s1, idx, s1_len);
		if (idx == std::string::npos)
			break;
		else
		{
			str.erase(idx, s1_len);
			std::cout << "erase: " << str << std::endl;
			str.insert(idx, s2, s2_len);
			std::cout << "insert: " << str << std::endl;
			replace_file << str << std::endl;
		}
	}
}

int main(int argc, char *argv[])
{
	if (!(argc == 4 ? true : false))
	{
		std::cout << "-> input error. Exit" << std::endl;
		exit(1);
	}

	std::ifstream original_file(argv[1]);

	if (!original_file.is_open())
	{
		std::cout << "-> file open error." << std::endl;
		exit(1);
	}
	std::ofstream replace_file(make_replace_filename(argv[1]));
	if (!replace_file.is_open())
	{
		std::cout << "-> replace file error." << std::endl;
		exit(1);
	}

	replace_str(original_file, replace_file, argv[2], argv[3]);
}
