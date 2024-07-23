#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	bool my_isdigit (char ch);
	bool vaildInput (std::string& token);
	void inputInStack(char mathOperator);
	int calculator (int first, int second, char mathOperator);
	int getResult (void);
};

#endif