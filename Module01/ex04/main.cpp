#include <fstream>
#include <iostream>
#include <string>

std::string make_replace_filename(const char *filename)
{
	std::string file_name = filename;
	std::string rp(".replace");
	std::string new_filename = file_name + rp;

	return (new_filename);
}

void replace_str (std::ifstream &original, std::ofstream &replace_file, std::string &s1, std::string &s2)
{
	std::string str;
	size_t s1_len = s1.size();
	size_t s2_len = s2.size();
	size_t idx = 0;

	while (std::getline(original, str))
	{
		idx = str.find(s1);
		while (idx != std::string::npos)
		{
			str = str.substr(0, idx) + s2 + str.substr(idx + s1_len);
			idx = str.find(s1, idx + s2_len);
		}
		replace_file << str << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (!(argc == 4 ? true : false))
	{
		std::cout << "-> input error. Exit" << std::endl;
		return (1);
	}

	std::ifstream original_file(argv[1]);
	if (!original_file.is_open())
	{
		std::cout << "-> file open error." << std::endl;
		return (1);
	}

	std::ofstream replace_file(make_replace_filename(argv[1]));
	if (!replace_file.is_open())
	{
		std::cout << "-> replace file open error." << std::endl;
		return (1);
	}
	
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	replace_str(original_file, replace_file, s1, s2);

	return (0);
}
