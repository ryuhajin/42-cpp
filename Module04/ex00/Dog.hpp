#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	~Dog();

	void	makeSound(void) const;
};

#endif