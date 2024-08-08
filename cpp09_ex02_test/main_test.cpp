#include "PmergeMe_test.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cerr << "Error : not enough input" << std::endl;
        return (1);
    }

    std::vector<int> input;
    if (!VectorSort::argvToVec(argc, argv, input))
        return (1);
    std::vector<std::pair<int, int> > afterInput;
    VectorSort::makePairVec(input, afterInput);
    VectorSort::printPairVec(afterInput);
    VectorSort::mergeInsertSort(afterInput);

	if (std::is_sorted(afterInput.begin(), afterInput.end(), compareUtils::compareFirstOnly) == false)
		std::cerr << "KO!" << std::endl;
    return (0);
}
