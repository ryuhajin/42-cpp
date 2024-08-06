#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cerrno>
#include <stdlib.h>

//vector

//./pmergeme "123" "56 7" "35" Error : Non-digit characters found.
bool PmergeMe::argvToVec(int argc, char *argv[], std::vector<std::pair<int, int> >& vec)
{
    char *endPtr;
    errno = 0;

    long value;
    for (int i = 1; i < argc; i++)
    {
        value = std::strtol(argv[i], &endPtr, 10);

        if (endPtr == argv[i])
        {
            std::cerr << "Error : digit not found." << std::endl;
            return (false);
        }
        else if (*endPtr != '\0')
        {
            std::cerr << "Error : Non-digit characters found." << std::endl;
            return (false);
        }
        else if (errno == ERANGE || value < 0 || value > INT_MAX)
        {
            std::cerr << "Error : digit out of range. " << std::endl;
            return (false);
        }

        vec.push_back(std::make_pair(i -1, value));
    }

    return (true);
}

void PmergeMe::printVec(std::vector<std::pair<int, int> > &vec)
{
    size_t idx = 0;
    for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << '[' << idx << ']' << ' ' << '[' << it->first <<  " , " << it->second << "]\n";
        ++idx;
    }
    std::cout << std::endl;
}

void PmergeMe::twoPlayerMatches(std::vector<std::pair<int, int> > &heads, std::vector<std::pair<int, int> > &tails)
{
    bool loseByDefault = heads.size() % 2 == 1 ? true : false;
    size_t pivot = heads.size() / 2;

    for (size_t i = 0; i < pivot; i++)
    {
        tails.push_back(heads.back());
        heads.pop_back();
    }

    if (loseByDefault)
    {
        tails.push_back(heads[pivot]);
        tails[pivot].first = -1; //bydefault check
        heads.erase(heads.begin() + pivot);
    }
}

void PmergeMe::comparePlayers (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    for (size_t i = 0; i < winners.size(); i++)
    {
        if (winners[i].second < losers[i].second)
            std::swap(winners[i], losers[i]);
    }
}

void PmergeMe::sort(std::vector<std::pair<int, int> > &players)
{
    if (players.size() == 1)
        return ;

    std::vector<std::pair<int, int> > tails;
    std::cout << "=============== Make pair ===============" << std::endl;
    twoPlayerMatches(players, tails);
    std::cout << "[winners]" << std::endl;
    PmergeMe::printVec(players);
    std::cout << "[losers]" << std::endl;
    PmergeMe::printVec(tails);

    std::cout << "=============== pair Swap ===============" << std::endl;
    comparePlayers(players, tails);
    std::cout << "[winners]" << std::endl;
    PmergeMe::printVec(players);
    std::cout << "[losers]" << std::endl;
    PmergeMe::printVec(tails);

    PmergeMe::sort(players); // 승자가 한명 남을 때 까지 재귀로 쌍을 짓고 그 쌍끼리 비교하여 승자조, 패자조를 나눔.
    std::cout << "=============== Index Match ===============" << std::endl;
    
}

//deque
