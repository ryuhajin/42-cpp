#include "PmergeMe_test.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

bool compareUtils::comparePairToFirst(const std::pair<int, int>& a, int value)
{
    return a.first < value;
}

bool compareUtils::comparePairToSecond(const std::pair<int, int>& a, int value)
{
    return a.second < value;
}

bool compareUtils::compareFirstOnly(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.first < b.first;
}

bool VectorSort::argvToVec(int argc, char *argv[], std::vector<int> &vec)
{
    int value;

    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        while (!iss.eof())
        {
            iss >> value;
            if (iss.fail() || value < 0)
            {
                std::cerr << "Error : invalid input." << std::endl;
                return (false);
            }
        vec.push_back(value);
        }
    }

    return (true);
}

void VectorSort::makePairVec(std::vector<int> &input, std::vector<std::pair<int, int> >& pairVec)
{
    size_t i = 1;
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        pairVec.push_back(std::make_pair(*it, i -1));
        i++;
    }
}

void VectorSort::printPairVec(std::vector<std::pair<int, int> > &vec)
{
    size_t idx = 0;
    for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << '[' << idx << ']' << ' ' << '[' << it->first <<  " , " << it->second << "]\n";
        ++idx;
    }
    std::cout << std::endl;
}

void VectorSort::PlayersMatches(std::vector<std::pair<int, int> > &heads, std::vector<std::pair<int, int> > &tails)
{
    bool loseByDefault = heads.size() % 2 == 1 ? true : false;
    size_t pivot = heads.size() / 2;

    for (size_t i = 0; i < pivot; i++)
    {
        tails.push_back(heads.back());
        heads[i].second = tails[i].first;
        tails[i].second = heads[i].first;
        heads.pop_back();
    }

    if (loseByDefault)
    {
        tails.push_back(heads[pivot]);
        tails[pivot].second = -1;
        heads.erase(heads.begin() + pivot);
    }
}

void VectorSort::playersCompare (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    for (size_t i = 0; i < winners.size(); i++)
    {
		std::cout << "swap = " << i << std::endl;
        if (winners[i].first < losers[i].first)
            std::swap(winners[i], losers[i]);
    }
}

void VectorSort::clearLoseByDefault (std::vector<std::pair<int, int> > &losers)
{
    std::vector<std::pair<int, int> > back;

    while (losers[0].second == -1)
    {
        back.push_back(losers[0]);
        losers.erase(losers.begin());
    }
    
    for (size_t i = 0; i < back.size(); i++)
    {
        losers.push_back(back[i]);
    }
}

void VectorSort::playersIdxRenumber (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    std::cout << "*************** IdxRenumber start! ********************" << std::endl;
    std::cout << " Original losers Idx " << std::endl;
    printPairVec(losers);

    std::vector<std::pair<int, int> >::iterator it;

    for (size_t i = 0; i < winners.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.end(), losers[i].second, compareUtils::comparePairToFirst);
        if (it != winners.end() && it->first == losers[i].second)
            losers[i].second = std::distance(winners.begin(), it);
    }

    std::sort(losers.begin(), losers.end(), compareUtils::ComparePair());
    clearLoseByDefault(losers);

    std::cout << " After losers Idx " << std::endl;
    printPairVec(losers);
}

void VectorSort::printInsert (std::vector<size_t> &insert)
{
    std::cout << "*************** insert Sequence print ********************" << std::endl;
    
    size_t i = 0;
    for (std::vector<size_t>::iterator it = insert.begin(); it != insert.end(); it++)
    {
        std::cout << '[' << i << ']' << " insert Idx = " << *it << '\n';
    }
    std::cout << std::endl;
}

std::vector<size_t> VectorSort::generateInsertOrder (size_t size)
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

void VectorSort::insertTails(std::vector<size_t> &insert, std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    std::vector<std::pair<int, int> >::iterator it;
    
    for (size_t i = 0; i < losers.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.begin() + insert[i] + i, losers[insert[i]]);
		std::cout << "i = " << i << "\n";
		std::cout << "범위 = " << insert[i] + i << std::endl;
		std::cout << "insert loser = " << losers[insert[i]].first << "\n";
		std::cout << "lower_bound it = " << (int)(*it).first << '\n' << std::endl;
        winners.insert(it, losers[insert[i]]);

		std::cout << "!!! insert Winner !!! " << std::endl;
		printPairVec(winners);
    }
}

void VectorSort::mergeInsertSort(std::vector<std::pair<int, int> > &players)
{
    if (players.size() == 1)
        return ;

    std::vector<std::pair<int, int> > tails;
    std::cout << "=============== Make pair ===============" << std::endl;
    PlayersMatches(players, tails);
    std::cout << "[winners]" << std::endl;
    printPairVec(players);
    std::cout << "[losers]" << std::endl;
    printPairVec(tails);

    std::cout << "=============== pair Swap ===============" << std::endl;
    playersCompare(players, tails);
    std::cout << "[winners]" << std::endl;
    printPairVec(players);
    std::cout << "[losers]" << std::endl;
    printPairVec(tails);

    mergeInsertSort(players);

    playersIdxRenumber(players, tails);
    
    std::cout << "=============== Index Match ===============" << std::endl;
    std::cout << "[winners]" << std::endl;
    printPairVec(players);
    std::cout << "[losers]" << std::endl;
    printPairVec(tails);

    std::vector<size_t> insertSequence = generateInsertOrder(tails.size());
    insertTails(insertSequence, players, tails);

    std::cout << "=============== Insert Tails After ===============" << std::endl;
    std::cout << "[winners]" << std::endl;
    printPairVec(players);
}
