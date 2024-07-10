#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
해야할것

1. 예외처리 잘 되는지 확인
	- addnumber vector _size 초과했을때 예외 잘 던지는지
	- shortSpan _size 작을때 예외 잘 던지는지
	- longestSpan _size 작을때 예외 잘 던지는지

2. 함수 잘 돌아가는지 확인
	- value 잘 들어가나 print로 찍어보기.
	- shortSpan / longestSpan 작동 잘 되나 print로 찍어보고 체크.

*/

int main(void)
{
    Span span(100);

    // 랜덤 숫자를 추가하기 위해 랜덤 시드 설정
    std::srand(std::time(0));

    try
	{
        // Span 객체에 10,000개의 랜덤 숫자 추가
        for (unsigned int i = 0; i < 100; i++) {
            int randomValue = std::rand();
            span.addNumber(randomValue);
        }
		span.print_value();
        std::cout << std::endl;
        
        // shortestSpan과 longestSpan 결과 출력
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

	return (0);
}
