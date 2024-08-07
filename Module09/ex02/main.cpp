#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr << "Error : Not enough input" << std::endl;
        return (1);
    }

    std::vector<std::pair<int, int> > vInput;
    if (!PmergeMe::argvToVec(argc, argv, vInput))
        return (1);
    std::cout << "=============== input vector ===============" << std::endl;
    PmergeMe::printVec(vInput);

    PmergeMe::sort(vInput);

	if (std::is_sorted(vInput.begin(), vInput.end()) == false)
		std::cerr << "KO!" << std::endl;
    return (0);
}