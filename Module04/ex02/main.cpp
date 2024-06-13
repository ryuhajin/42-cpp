# include "Animal.hpp"
# include "Brain.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;

	return (0);
}
