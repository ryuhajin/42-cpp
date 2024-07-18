#ifndef RPN_HPP
# define RPN_HPP

/* include */
#include <string>

class RPN : public ParentClass
{
private:
public:
	RPN();
	RPN(const RPN& rhs);
	RPN& operator=(const RPN& rhs);
	~RPN();
};

#endif