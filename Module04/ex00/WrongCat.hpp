#ifndef WRONGCAT_CPP
# define WRONGCAT_CPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& rhs);
	WrongCat& operator=(const WrongCat& rhs);
	~WrongCat();

	void	makeSound(void) const;
};

#endif
