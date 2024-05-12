#include <iostream>
#include <string>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR= &str;
	std::string &stringREF = str;

	std::cout << std::endl;

	std::cout << "string의 메모리 주소 : " << &str << std::endl;
	std::cout << "string PRT이 가리키는 메모리 주소 : "  << &stringPTR << std::endl;
	std::cout << "string REF가 가리키는 메모리 주소 : "  << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "string의 값 : " << str << std::endl;
	std::cout << "string PRT이 가리키는 값 : " << *stringPTR << std::endl;
	std::cout << "string REF가 가리키는 값 : " << stringREF << std::endl;

	std::cout << std::endl;
	
	return (0);
}
