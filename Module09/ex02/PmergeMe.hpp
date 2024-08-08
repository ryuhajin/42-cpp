# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
namespace VectorSort
{
    bool argvToVec(int argc, char *argv[], std::vector<int> &vec);
    void makePairVec(std::vector<int> &input, std::vector<std::pair<int, int> > &pairVec);
    void printPairVec(std::vector<std::pair<int, int> > &vec);
    void PlayersMatches(std::vector<std::pair<int, int> > & heads, std::vector<std::pair<int, int> > &tails);
    void playersCompare (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers);
    void clearLoseByDefault (std::vector<std::pair<int, int> > &losers);
    void playersIdxRenumber (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers);
    std::vector<size_t> generateInsertOrder (size_t size);
    void insertTails(std::vector<size_t> &insert, std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers);
    void mergeInsertSort(std::vector<std::pair<int, int> > &players);
}

namespace DequeSort
{
    bool argvToDeque(int argc, char *argv[], std::deque<int> &deque);
    void makePairDeque(std::deque<int> &input, std::deque<std::pair<int, int> >& pairDeque);
    void printPairDeque(std::deque<std::pair<int, int> > &deque);
    void PlayersMatches(std::deque<std::pair<int, int> > & heads, std::deque<std::pair<int, int> > &tails);
    void playersCompare (std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers);
    void clearLoseByDefault (std::deque<std::pair<int, int> > &losers);
    void playersIdxRenumber (std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers);
    std::deque<size_t> generateInsertOrder (size_t size);
    void insertTails(std::deque<size_t> &insert, std::deque<std::pair<int, int> > &winners, std::deque<std::pair<int, int> > &losers);
    void mergeInsertSort(std::deque<std::pair<int, int> > &players);
}

namespace compareUtils
{
    bool comparePairToFirst(const std::pair<int, int>& a, int value);
    bool comparePairToSecond(const std::pair<int, int>& a, int value);
    bool compareFirstOnly(const std::pair<int, int>& a, const std::pair<int, int>& b);
    struct ComparePair
    {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return a.second < b.second;
        }
    };
}

#endif