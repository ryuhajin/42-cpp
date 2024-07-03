#include "whatever.hpp"

#include <iostream>
#include <string>

// :: <- 네임 스페이스 지정 없이 선언된 모든 이름이 포함되는 공간. 전역 네임 스페이스
// int main( void ) {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }


int main() {
    char a = 'a', b = 'b';
    std::string s1 = "abc", s2 = "123";
    int x = 10, y = 20;
    double i = 42.42, j = 1.1;

    //swap
    std::cout << "================== Swap ==================" << std::endl;
    std::cout << "[char] Swap" << std::endl;
    std::cout << "Before: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After: a = " << a << ", b = " << b << '\n' << std::endl;

    std::cout << "[string] Swap" << std::endl;
    std::cout << "Before: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << "After: s1 = " << s1 << ", s2 = " << s2 << '\n' << std::endl;

    std::cout << "[int] Swap" << std::endl;
    std::cout << "Before: x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "After: x = " << x << ", y = " << y << '\n' << std::endl;

    std::cout << "[double] Swap" << std::endl;
    std::cout << "Before: i = " << i << ", j = " << j << std::endl;
    ::swap(i, j);
    std::cout << "After: i = " << i << ", j = " << j << "\n\n" << std::endl;

    //min
    std::cout << "================== Min ==================" << std::endl;
    std::cout << "[char] Min" << std::endl;
    std::cout << "Min of a and b: " << ::min(a, b) << '\n' << std::endl;

    std::cout << "[string] Min" << std::endl;
    std::cout << "Min of s1 and s2: " << ::min(s1, s2) << '\n' << std::endl;

    std::cout << "[int] Min" << std::endl;
    std::cout << "Min of x and y: " << ::min(x, y) << '\n' << std::endl;

    std::cout << "[double] Min" << std::endl;
    std::cout << "Min of i and j: " << ::min(i, j) << "\n\n" << std::endl;
    
    //max
    std::cout << "================== Max ==================" << std::endl;
    std::cout << "[char] Max" << std::endl;
    std::cout << "Max of a and b: " << ::max(a, b) << '\n' << std::endl;

    std::cout << "[string] Max" << std::endl;
    std::cout << "Max of s1 and s2: " << ::max(s1, s2) << '\n' << std::endl;

    std::cout << "[int] Max" << std::endl;
    std::cout << "Max of x and y: " << ::max(x, y) << '\n' << std::endl;

    std::cout << "[double] Max" << std::endl;
    std::cout << "Max of i and j: " << ::max(i, j) << '\n' << std::endl;

    return (0);
}
