#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
public:
	Dog();
	Dog(const std::string& in_string);
	Dog(const Dog& in);
	Dog& operator=(const Dog& in);
	~Dog();

	void	makeSound(void) const;
};

#endif