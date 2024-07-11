#include <iostream>
#include <limits>

int main() {
    float maxFloat = std::numeric_limits<float>::max();
    float minFloat = std::numeric_limits<float>::min();
    float lowestFloat = std::numeric_limits<float>::lowest();

    std::cout << "Maximum float value: " << maxFloat << std::endl;
    std::cout << "Minimum positive float value: " << minFloat << std::endl;
    std::cout << "Minimum float value: " << lowestFloat << std::endl;

    return 0;
}
