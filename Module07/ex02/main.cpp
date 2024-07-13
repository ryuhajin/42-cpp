#include "Array.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

void	check_leak(void)
{
	system("leaks ex02");
}

int main(void)
{
	atexit(check_leak);

	std::cout << "================== Deepcopy check ==================" << std::endl;
    Array<int> originalArray(5);
    for (unsigned int i = 0; i < originalArray.size(); ++i)
        originalArray[i] = i + 1;

    Array<int> copiedArray = originalArray;

    copiedArray[0] = 100;

    std::cout << '\n' << "Original array after copying:" << std::endl;
    for (unsigned int i = 0; i < originalArray.size(); ++i)
	{
        std::cout << "originalArray[" << i << "] = " << originalArray[i] << std::endl;
    }

    std::cout << '\n' << "Copied array:" << std::endl;
    for (unsigned int i = 0; i < copiedArray.size(); ++i)
	{
        std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
    }
	std::cout << std::endl;

	std::cout << "================== type check ==================" << std::endl;
    Array<double> doubleArray(3);
    doubleArray[0] = 1.1;
    doubleArray[1] = 2.2;
    doubleArray[2] = 3.3;

    std::cout << "doubleArray:" << std::endl;
    for (unsigned int i = 0; i < doubleArray.size(); ++i)
	{
        std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
    }

    Array<std::string> stringArray(2);
    stringArray[0] = "Hello";
    stringArray[1] = "World";

    std::cout << '\n' << "stringArray:" << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); ++i)
	{
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }
	std::cout << std::endl;

	std::cout << "================== const check ==================" << std::endl;
    Array<int> normalArray(4);
    for (unsigned int i = 0; i < normalArray.size(); ++i)
	{
        normalArray[i] = i * 3;
    }

    const Array<int> constArray(normalArray);

    std::cout << "constArray:" << std::endl;
    for (unsigned int i = 0; i < constArray.size(); ++i)
	{
        std::cout << "constArray[" << i << "] = " << constArray[i] << '\n' << std::endl;
    }

	std::cout << "================== exception check ==================" << std::endl;
    try
	{
        std::cout << "Accessing out of range index: " << normalArray[10] << std::endl;
		std::cout << "Accessing out of range index: " << normalArray[-1] << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

    return (0);
}
