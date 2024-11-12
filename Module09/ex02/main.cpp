#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <ctime>

double usCalculator (timeval &start, timeval &end)
{
	long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double runtime = seconds + microseconds * 1e-6; // 1 second = 1,000,000 microsecond

	return (runtime);
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr << "Error : not enough input" << std::endl;
        return (1);
    }

	struct timeval vectorStart, vectorEnd, dequeStart,dequeEnd;

    //STL vector type
    std::vector<int> vInput;
    if (!VectorSort::argvToVec(argc, argv, vInput))
        return (1);
    std::vector<std::pair<int, int> > after_vInput;
    VectorSort::makePairVec(vInput, after_vInput);

    //STL vecotr type time recode
    gettimeofday(&vectorStart, NULL);
    VectorSort::mergeInsertSort(after_vInput);
	gettimeofday(&vectorEnd, NULL);

    //STL deque type
    std::deque<int> dInput;
    if (!DequeSort::argvToDeque(argc, argv, dInput))
        return (1);
    std::deque<std::pair<int, int> > after_dInput;
    DequeSort::makePairDeque(dInput, after_dInput);

    //STL deque type time recode
    gettimeofday(&dequeStart, NULL);
    DequeSort::mergeInsertSort(after_dInput);
    gettimeofday(&dequeEnd, NULL);

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
    std::cout << "Time to process a range of " << vInput.size() << " elements with Vector : " << std::fixed << usCalculator(vectorStart, vectorEnd) << " us" << std::endl;
	std::cout << "Time to process a range of " << dInput.size() << " elements with Deque : " << std::fixed << usCalculator(dequeStart, dequeEnd) << " us" << std::endl;
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
