#include <iostream>
#include <stack>
#include <deque>

// MutantStack 클래스 정의
template<typename T>
class MutantStack : public std::stack<T> {
public:
    // std::stack의 기본 컨테이너 타입을 가져옵니다.
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // begin() 함수 정의
    iterator begin() {
        return std::stack<T>::c.begin();
    }

    // end() 함수 정의
    iterator end() {
        return std::stack<T>::c.end();
    }

    // const_iterator 버전의 begin() 함수 정의
    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    // const_iterator 버전의 end() 함수 정의
    const_iterator end() const {
        return std::stack<T>::c.end();
    }

    // reverse_iterator 버전의 rbegin() 함수 정의
    reverse_iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }

    // reverse_iterator 버전의 rend() 함수 정의
    reverse_iterator rend() {
        return std::stack<T>::c.rend();
    }

    // const_reverse_iterator 버전의 rbegin() 함수 정의
    const_reverse_iterator rbegin() const {
        return std::stack<T>::c.rbegin();
    }

    // const_reverse_iterator 버전의 rend() 함수 정의
    const_reverse_iterator rend() const {
        return std::stack<T>::c.rend();
    }

    // const_iterator 버전의 cbegin() 함수 정의
    const_iterator cbegin() const {
        return std::stack<T>::c.cbegin();
    }

    // const_iterator 버전의 cend() 함수 정의
    const_iterator cend() const {
        return std::stack<T>::c.cend();
    }

    // const_reverse_iterator 버전의 crbegin() 함수 정의
    const_reverse_iterator crbegin() const {
        return std::stack<T>::c.crbegin();
    }

    // const_reverse_iterator 버전의 crend() 함수 정의
    const_reverse_iterator crend() const {
        return std::stack<T>::c.crend();
    }
};

// 테스트 코드
int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Forward iteration:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Reverse iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::stack<int> s(mstack);
    return 0;
}
