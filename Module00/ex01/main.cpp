#include "Phonebook.h"
#include <string>

		/*1. ADD (새 연락처 저장)
			1. 성이 뭐니
			2. 이름이 뭐니
			3. 별명이 뭐니
			4. 폰 번호 뭐니
			5. 너의 다크 시크릿이 뭐니
		2. SEARCH (특정 연락처 출력)
			1. 연락처 출력 (폰북 출력)
			2. 인덱스 물어보기
				-> 숫자가 아니거나 인덱스 범위를 벗어난 경우 다시 물어보기
			3. 입력받은 인덱스의 정보를 출력
		3. EXIT
			종료.
		-> 다른 명령은 버려짐.
		*/

int main(void)
{
	PhoneBook p;

	while (true)
	{
		p.print_command();
		std::string input;
		p.input_check(input);
		if (p.command_check(input) == false)
			continue;
		else
			p.select_command(input);
	}
	return (0);
}
