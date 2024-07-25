#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // Test different types
	std::cout << "================== different type test ==================" << std::endl;

	MutantStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    
    std::cout << "[intStack]" << std::endl;
    while (!intStack.empty()) {
        std::cout << intStack.top() << " ";
        intStack.pop();
    }
    std::cout << '\n' << std::endl;

    MutantStack<std::string> stringStack;
    stringStack.push("one");
    stringStack.push("two");
    stringStack.push("three");

    std::cout << "[stringStack]" << std::endl;
    while (!stringStack.empty()) {
        std::cout << stringStack.top() << " ";
        stringStack.pop();
    }
    std::cout << '\n' << std::endl;
    
    // Test iterators
	std::cout << "================== iterator test ==================" << std::endl;
    MutantStack<int> stack;
    for (int i = 1; i <= 5; ++i) stack.push(i);

    std::cout << "iterator: ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "const_iterator: ";
    for (MutantStack<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "reverse_iterator: ";
    for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "const_reverse_iterator: ";
    for (MutantStack<int>::const_reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n' << std::endl;

    // Test with different containers
	std::cout << "================== container type test ==================" << std::endl;
    MutantStack<int, std::vector<int> > vectorStack;
    vectorStack.push(1);
    vectorStack.push(2);
    vectorStack.push(3);

    std::cout << "[Make vector type Stack]" << std::endl;
    while (!vectorStack.empty()) {
        std::cout << vectorStack.top() << " ";
        vectorStack.pop();
    }
    std::cout << '\n' << std::endl;

    std::cout << "[vector type stack irerator]" << std::endl;
    for (int i = 1; i <= 3; ++i) vectorStack.push(i);

    std::cout << "iterator: ";
    for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin(); it != vectorStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "reverse_iterator: ";
    for (MutantStack<int, std::vector<int> >::reverse_iterator it = vectorStack.rbegin(); it != vectorStack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n' << std::endl;

    MutantStack<int, std::list<int> > listStack;
    listStack.push(4);
    listStack.push(5);
    listStack.push(6);

    std::cout << "[Make list type Stack]" << std::endl;
    while (!listStack.empty()) {
        std::cout << listStack.top() << " ";
        listStack.pop();
    }
    std::cout << '\n' << std::endl;

    std::cout << "[list type stack iterator]" << std::endl;
    for (int i = 4; i <= 6; ++i) listStack.push(i);

    std::cout << "iterator: ";
    for (MutantStack<int, std::list<int> >::iterator it = listStack.begin(); it != listStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "reverse_iterator: ";
    for (MutantStack<int, std::list<int> >::reverse_iterator it = listStack.rbegin(); it != listStack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n' << std::endl;

    return (0);
}
