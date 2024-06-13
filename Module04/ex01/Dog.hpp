#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const std::string& in_string);
	Dog(const Dog& in);
	Dog& operator=(const Dog& in);
	~Dog();

	void	makeSound(void) const;
	Brain*	getBrain(void);
	void	setBrain (const std::string& idea, int i);
};

#endif
