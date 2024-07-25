#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
	std::vector<int> randomNumbers(100);
	
	for (int i = 0; i < 100; ++i)
	{
        randomNumbers[i] = std::rand() % 10001;
    }

	try
	{
		Span sp4(100);
		sp4.addNumbers(randomNumbers.begin(), randomNumbers.end());
		std::cout << "sp4[100] = ";
		sp4.print_value();
		std::cout << std::endl;

		std::cout << "sorted sp4[100] = ";
		std::vector<int> sortedSpan(sp4.getNumbers());
		std::sort(sortedSpan.begin(), sortedSpan.end());
		for (std::vector<int>::iterator it = sortedSpan.begin();
		it != sortedSpan.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << '\n' << std::endl;

		std::cout << "shortestSpan: " << sp4.shortestSpan() << std::endl;
		std::cout << "longerstSpan: " << sp4.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
