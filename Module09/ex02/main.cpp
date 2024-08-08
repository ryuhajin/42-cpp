#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr << "Error : not enough input" << std::endl;
        return (1);
    }

    //STL vector type
    std::vector<int> vInput;
    if (!VectorSort::argvToVec(argc, argv, vInput))
        return (1);
    std::vector<std::pair<int, int> > after_vInput;
    VectorSort::makePairVec(vInput, after_vInput);

    //STL vecotr type time recode
    std::clock_t vecStart = std::clock();
    VectorSort::mergeInsertSort(after_vInput);
    std::clock_t vecEnd = std::clock();

    //STL deque type
    std::deque<int> dInput;
    if (!DequeSort::argvToDeque(argc, argv, dInput))
        return (1);
    std::deque<std::pair<int, int> > after_dInput;
    DequeSort::makePairDeque(dInput, after_dInput);

    //STL deque type time recode
    std::clock_t dequeStart = std::clock();
    DequeSort::mergeInsertSort(after_dInput);
    std::clock_t dequeEnd = std::clock();

    //before after Vector Print
    std::cout << std::endl;
    std::cout << "[Vector]" << std::endl;
    std::cout << "Before: ";
    for(std::vector<int>::iterator it = vInput.begin(); it != vInput.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    VectorSort::printPairVec(after_vInput);
    std::cout << std::endl;

    //before after Deque Print
    std::cout << "[Deque]" << std::endl;
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = dInput.begin(); it != dInput.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    DequeSort::printPairDeque(after_dInput);
    std::cout << std::endl;

    //recode print
    std::cout << "Time to process a range of " << vInput.size() << " elements with Vector : " << vecEnd - vecStart << " us" << std::endl;
	std::cout << "Time to process a range of " << dInput.size() << " elements with Deque : " << dequeEnd - dequeStart << " us" << std::endl;
    std::cout << std::endl;

    //sorted check
    // std::cout << "[Sort check]" << std::endl;
	// if (std::is_sorted(after_vInput.begin(), after_vInput.end(), compareUtils::compareFirstOnly) == false)
	// 	std::cerr << "vector sort KO!" << std::endl;
    // else
    //     std::cout << "vector sort OK." << std::endl;

    // if (std::is_sorted(after_dInput.begin(), after_dInput.end(), compareUtils::compareFirstOnly) == false)
    //     std::cerr << "deque sort KO!" << std::endl;
    // else
    //     std::cout << "deque sort OK." << std::endl;
    // std::cout << std::endl;
    return (0);
}
