#include "PmergeMe.hpp"
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
    for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << it->first <<  " ";
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
    std::vector<std::pair<int, int> >::iterator it;

    for (size_t i = 0; i < winners.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.end(), losers[i].second, compareUtils::comparePairToFirst);
        if (it != winners.end() && it->first == losers[i].second)
            losers[i].second = std::distance(winners.begin(), it);
    }

    std::sort(losers.begin(), losers.end(), compareUtils::ComparePair());
    clearLoseByDefault(losers);
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

    return (insertSequence);
}

void VectorSort::insertTails(std::vector<size_t> &insert, std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers)
{
    std::vector<std::pair<int, int> >::iterator it;
    
    for (size_t i = 0; i < losers.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.begin() + insert[i] + i, losers[insert[i]]);
        winners.insert(it, losers[insert[i]]);
    }
}

void VectorSort::mergeInsertSort(std::vector<std::pair<int, int> > &players)
{
    if (players.size() == 1)
        return ;

    std::vector<std::pair<int, int> > tails;
    PlayersMatches(players, tails);
    playersCompare(players, tails);
    mergeInsertSort(players);

    playersIdxRenumber(players, tails);

    std::vector<size_t> insertSequence = generateInsertOrder(tails.size());
    insertTails(insertSequence, players, tails);
}

// Deque start //

bool DequeSort::argvToDeque(int argc, char *argv[], std::deque<int> &vec)
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

void DequeSort::makePairDeque(std::deque<int> &input, std::deque<std::pair<int, int> >& pairVec)
{
    size_t i = 1;
    for (std::deque<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        pairVec.push_back(std::make_pair(*it, i -1));
        i++;
    }
}

void DequeSort::printPairDeque(std::deque<std::pair<int, int> > &deque)
{
    for (std::deque<std::pair<int, int> >::iterator it = deque.begin(); it != deque.end(); ++it)
    {
        std::cout << it->first <<  " ";
    }
    std::cout << std::endl;
}

void DequeSort::PlayersMatches(std::deque<std::pair<int, int> > &heads, std::deque<std::pair<int, int> > &tails)
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

void DequeSort::playersCompare (std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers)
{
    for (size_t i = 0; i < winners.size(); i++)
    {
        if (winners[i].first < losers[i].first)
            std::swap(winners[i], losers[i]);
    }
}

void DequeSort::clearLoseByDefault (std::deque<std::pair<int, int> > &losers)
{
    std::deque<std::pair<int, int> > back;

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

void DequeSort::playersIdxRenumber (std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers)
{
    std::deque<std::pair<int, int> >::iterator it;

    for (size_t i = 0; i < winners.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.end(), losers[i].second, compareUtils::comparePairToFirst);
        if (it != winners.end() && it->first == losers[i].second)
            losers[i].second = std::distance(winners.begin(), it);
    }

    std::sort(losers.begin(), losers.end(), compareUtils::ComparePair());
    clearLoseByDefault(losers);
}

std::deque<size_t> DequeSort::generateInsertOrder (size_t size)
{
    std::deque<size_t> insertSequence(size);
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

    return (insertSequence);
}

void DequeSort::insertTails(std::deque<size_t> &insert, std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers)
{
    std::deque<std::pair<int, int> >::iterator it;
    
    for (size_t i = 0; i < losers.size(); i++)
    {
        it = std::lower_bound(winners.begin(), winners.begin() + insert[i] + i, losers[insert[i]]);
        winners.insert(it, losers[insert[i]]);
    }
}

void DequeSort::mergeInsertSort(std::deque<std::pair<int, int> > &players)
{
    if (players.size() == 1)
        return ;

    std::deque<std::pair<int, int> > tails;
    PlayersMatches(players, tails);
    playersCompare(players, tails);
    mergeInsertSort(players);

    playersIdxRenumber(players, tails);

    std::deque<size_t> insertSequence = generateInsertOrder(tails.size());
    insertTails(insertSequence, players, tails);
}
