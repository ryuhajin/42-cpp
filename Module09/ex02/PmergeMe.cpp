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

void PmergeMe::PlayersMatches(std::vector<std::pair<int, int> > &heads, std::vector<std::pair<int, int> > &tails)
{
    bool loseByDefault = heads.size() % 2 == 1 ? true : false;
    size_t pivot = heads.size() / 2;

    for (size_t i = 0; i < pivot; i++)
    {
        tails.push_back(heads.back());
        tails[i].first = i;
        heads.pop_back();
    }

    if (loseByDefault)
    {
        tails.push_back(heads[pivot]);
        tails[pivot].first = -1; //bydefault check
        heads.erase(heads.begin() + pivot);
    }
}

void PmergeMe::playersCompare (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    for (size_t i = 0; i < winners.size(); i++)
    {
        if (winners[i].second < losers[i].second)
            std::swap(winners[i], losers[i]);
    }
}

void playersIdxRenumber (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    std::vector<std::pair<int, int> > renumberTails;
    for (size_t i = 0; i < winners.size(); i++)
    {
        renumberTails.push_back(losers[winners[i].first]);
    }

    if (winners.size() < losers.size())
        renumberTails.push_back(losers.back());

    losers = renumberTails;
}

void printInsert (std::vector<size_t> &insert)
{
    std::cout << "*************** insert Sequence print ********************" << std::endl;
    
    size_t i = 0;
    for (std::vector<size_t>::iterator it = insert.begin(); it != insert.end(); it++)
    {
        std::cout << '[' << i << ']' << " insert Idx = " << *it << '\n';
    }
    std::cout << std::endl;
}

std::vector<size_t> generateInsertOrder (size_t size)
{
    std::vector<size_t> insertSequence(size);
    size_t tailsIdx = 0;
    size_t squares = 2;
    size_t insertIdx = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (i > insertIdx)
        {
            squares *= 2;
            insertIdx = squares - i -1;

            if (insertIdx >= size)
                insertIdx = size -1;
            
            tailsIdx = insertIdx;
        }
        insertSequence[i] = tailsIdx--;
    }

    printInsert(insertSequence);
    return (insertSequence);
}

void insertTails(std::vector<size_t> &insert, std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    for (size_t i = 0; i < insert.size(); i++)
    {
        
    }
}

void PmergeMe::sort(std::vector<std::pair<int, int> > &players)
{
    if (players.size() == 1)
        return ;

    std::vector<std::pair<int, int> > tails;
    std::cout << "=============== Make pair ===============" << std::endl;
    PlayersMatches(players, tails);
    std::cout << "[winners]" << std::endl;
    PmergeMe::printVec(players);
    std::cout << "[losers]" << std::endl;
    PmergeMe::printVec(tails);

    std::cout << "=============== pair Swap ===============" << std::endl;
    playersCompare(players, tails);
    std::cout << "[winners]" << std::endl;
    PmergeMe::printVec(players);
    std::cout << "[losers]" << std::endl;
    PmergeMe::printVec(tails);

    PmergeMe::sort(players); // 승자가 한명 남을 때 까지 재귀로 쌍을 짓고 그 쌍끼리 비교하여 승자조, 패자조를 나눔.
    std::cout << "=============== Index Match ===============" << std::endl;
    playersIdxRenumber(players, tails); // tails remaster = players idx와 동일하게 있음.
    std::cout << "[winners]" << std::endl;
    PmergeMe::printVec(players);
    std::cout << "[losers]" << std::endl;
    PmergeMe::printVec(tails);

    std::vector<size_t> insertSequence = generateInsertOrder(tails.size());
    insertTails(insertSequence, players, tails);
}

//deque
