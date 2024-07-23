#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

// 타입 T에 여러 가지 타입을 넣고 동작이 잘 되는지 테스트
void testType() {
    MutantStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    
    std::cout << "Testing with int type:" << std::endl;
    while (!intStack.empty()) {
        std::cout << intStack.top() << " ";
        intStack.pop();
    }
    std::cout << std::endl;

    MutantStack<std::string> stringStack;
    stringStack.push("one");
    stringStack.push("two");
    stringStack.push("three");

    std::cout << "Testing with string type:" << std::endl;
    while (!stringStack.empty()) {
        std::cout << stringStack.top() << " ";
        stringStack.pop();
    }
    std::cout << std::endl;
}

// 클래스에 구현되어있는 4종류의 이터레이터 테스트
void testIterators() {
    MutantStack<int> stack;
    for (int i = 1; i <= 5; ++i) stack.push(i);

    std::cout << "Testing iterators:" << std::endl;

    // iterator
    std::cout << "iterator: ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // const_iterator
    std::cout << "const_iterator: ";
    for (MutantStack<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // reverse_iterator
    std::cout << "reverse_iterator: ";
    for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // const_reverse_iterator
    std::cout << "const_reverse_iterator: ";
    for (MutantStack<int>::const_reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// MutantStack의 부모인 stack에 list, vector를 넣어 동작하나 테스트
void testContainerTypes() {
    MutantStack<int, std::vector<int> > vectorStack;
    vectorStack.push(1);
    vectorStack.push(2);
    vectorStack.push(3);

    std::cout << "Testing with vector as container:" << std::endl;
    while (!vectorStack.empty()) {
        std::cout << vectorStack.top() << " ";
        vectorStack.pop();
    }
    std::cout << std::endl;

    // Using iterators
    std::cout << "Using iterators with vector as container:" << std::endl;
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
    std::cout << std::endl;

    MutantStack<int, std::list<int> > listStack;
    listStack.push(4);
    listStack.push(5);
    listStack.push(6);

    std::cout << "Testing with list as container:" << std::endl;
    while (!listStack.empty()) {
        std::cout << listStack.top() << " ";
        listStack.pop();
    }
    std::cout << std::endl;

    // Using iterators
    std::cout << "Using iterators with list as container:" << std::endl;
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
    std::cout << std::endl;
}

int main() {
    // Test different types
    testType();
    
    // Test iterators
    testIterators();

    // Test with different containers
    testContainerTypes();

    return 0;
}
