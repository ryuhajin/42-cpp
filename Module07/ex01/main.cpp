#include "iter.hpp"
#include <string>

template <typename T>
void printValue(const T& value)
{
    std::cout << value << " ";
}

template <typename T>
void doubleValue(T& value)
{
    value *= 2;
}

int main (void)
{
    int int_arry[5] = {-1, 0, 1, 2, 3};
    const char char_arry[5] = {'1', '2', 'a', 'b', 'c'};
    const std::string string_arry[3] = {"s1", "s2", "s3"};
    float float_arry[2] = {1.1, 2.2};

    //print
    std::cout << "================== printValue ==================" << std::endl;
    std::cout << "[int] ";
    ::iter<int>(int_arry, 5, ::printValue<int>);
    std::cout << std::endl;

    std::cout << "[char] ";
    ::iter<char>(char_arry, 5, ::printValue<char>);
    std::cout << std::endl;

    std::cout << "[string] ";
    ::iter<std::string>(string_arry, 3, ::printValue<std::string>);
    std::cout << std::endl;

    std::cout << "[float] ";
    ::iter<float>(float_arry, 2, ::printValue<float>);
    std::cout << std::endl;

    //double
    std::cout << "================== doubleValue ==================" << std::endl;
    std::cout << "[int] ";
    ::iter(int_arry, 5, ::doubleValue);
    ::iter(int_arry, 5, ::printValue);
    std::cout << std::endl;

    std::cout << "[float] ";
    ::iter(float_arry, 2, ::doubleValue);
    ::iter(float_arry, 2, ::printValue);
    std::cout << std::endl;

    return (0);
}
