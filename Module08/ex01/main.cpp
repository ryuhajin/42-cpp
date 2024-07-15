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

================== Iterator test ==================
sp4[20] = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
shortestSpan: 0
longerstSpan: 0

*/

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "================== simple test ==================" << std::endl;
	std::cout << "sp[5] = ";
	sp.print_value();
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longerstSpan: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "================== exception test ==================" << std::endl;
	try
    {
        sp.addNumber(1);
	}
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	try
    {
        Span sp2(1);
        sp2.addNumber(1);
        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl; // 예외 발생해야 함
    }
    catch (const std::exception& e)
    {
    	std::cerr << e.what() << std::endl;
    }

	try
    {
        Span sp3(1);
    	sp3.addNumber(1);
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl; // 예외 발생해야 함
    }
    catch (const std::exception& e)
    {
    	std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

	std::cout << "================== Iterator test ==================" << std::endl;
	std::srand(std::time(0));
	std::vector<int> randomNumbers(20);
	std::generate(randomNumbers.begin(), randomNumbers.end(), std::rand);

	Span sp4(20);
	sp4.addNumbers(randomNumbers.begin(), randomNumbers.end());
	
	std::cout << "sp4[20] = ";
	sp4.print_value();
	std::cout << "shortestSpan: " << sp4.shortestSpan() << std::endl;
	std::cout << "longerstSpan: " << sp4.longestSpan() << std::endl;
	std::cout << std::endl;

	return (0);
}
