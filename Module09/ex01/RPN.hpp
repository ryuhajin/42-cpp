#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN : public 
{
private:
	stack<int> _rpn;
public:
	RPN();
	RPN(const RPN& rhs);
	RPN& operator=(const RPN& rhs);
	~RPN();
};

#endif