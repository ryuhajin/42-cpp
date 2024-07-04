#include "Array.hpp"

#include <iostream>
#include <string>

/*

체크 해야할 것
1. leaks 검사
2. 깊은 복사 확인
3. int말고 다른 타입의 array 동작 확인
4. const/!const 다 잘 돌아가나 확인

*/

int main(void)
{
    try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test constructor with size parameter
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        // Test assignment operator
        Array<int> arr3 = arr2;
        std::cout << "arr3 size (after assignment from arr2): " << arr3.size() << std::endl;

        // Test copy constructor
        Array<int> arr4(arr2);
        std::cout << "arr4 size (after copying arr2): " << arr4.size() << std::endl;

        // Modify arr2 and check arr3 and arr4 are not affected
        arr2[0] = 10;
        std::cout << "arr2[0]: " << arr2[0] << std::endl;
        std::cout << "arr3[0] (should be 0): " << arr3[0] << std::endl;
        std::cout << "arr4[0] (should be 0): " << arr4[0] << std::endl;

        // Test subscript operator with out-of-bounds access
        std::cout << "Accessing out of bounds (should throw exception): " << std::endl;
        std::cout << arr2[5] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test with std::string type
    try {
        Array<std::string> arr5(3);
        arr5[0] = "hello";
        arr5[1] = "world";
        arr5[2] = "!";
        std::cout << "arr5[0]: " << arr5[0] << std::endl;
        std::cout << "arr5[1]: " << arr5[1] << std::endl;
        std::cout << "arr5[2]: " << arr5[2] << std::endl;

        // Accessing out of bounds
        std::cout << arr5[3] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
