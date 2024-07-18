#include "RPN.hpp"
#include <iostream>
#include <string>

/*
"8 9 * 9 - 9 - 9 - 4 - 1 +"

후위 연산의 조건
1. 스택엔 언제나 두개의 숫자만 들어올 수 있다.
	-> 이는 계산할 때, 두개의 숫자를 꺼내어 계산하기 때문이다.
2. 스택에 두개의 숫자가 채워졌을 경우, 다음 input으로 들어오는 값이 연산자가 아니라면 오류이다.
3. 스택에 한개의 숫자가 채워졌을 경우, 다음 input으로 들어오는 값이 연산자라면 오류이다.

if (stack.size < 3)
	{ 
		스택에 첫번째로 들어가는 숫자거나, 두번째로 들어가는 숫자인지 체크한다.
		세번째로 들어가는 숫자일경우 1 + 2 3 = 과 같은 이상한 수식이 되어버린다.

	2. char '8'을 int 8로 변환한다.
		2-1. int 8 이 -1 < n < 10 범위에 있나 확인한다.
		 	범위에 없다면 에러 출력 후 종료 (exit(1))
	2-2. stack에 int 8을 넣는다.
	}
else
	{ 
		stack.size 가 2보다 크다면 계산기를 부른다.
		
		3-1. "+-/*"와 같은 기호라면 stack[1] "+-/*" stack[2]의 계산 후 결과 값을 리턴한다.
		3-2. 숫자나 다른 기호라면 에러 출력 후 종료.
	}
*/

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error : Invalid input." << ste::endl;
		return (1);
	}

	std::string argument(argv[1]);
	while (getline)

	return (0);
}
