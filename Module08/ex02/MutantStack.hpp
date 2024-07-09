#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack();
	MutantStack(const MutantStack& rhs);
	MutantStack& operator=(const MutantStack& rhs);
	~MutantStack();
};

#endif