#include <vector>
#include <deque>

class PmergeMe
{
private:
    // std::vector<int> _sort;
    // std::deque<int> _sort;
public:
    static bool argvToVec(int argc, char *argv[], std::vector<std::pair<int, int> >& vec);
    static void printVec(std::vector<std::pair<int, int> > &vec);
    static void twoPlayerMatches(std::vector<std::pair<int, int> > & heads, std::vector<std::pair<int, int> > &tails);
    static void sort(std::vector<std::pair<int, int> > & players);
    static void comparePlayers (std::vector<std::pair<int, int> > &winners, std::vector<std::pair<int, int> > &losers);
};
