# include "Animal.hpp"
# include "Brain.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include <iostream>
# include <string>
# include <sstream>

const std::string itoString(int num)
{
	std::stringstream itoS;

	itoS << num;

	return (itoS.str());
}

int main(void)
{
	Animal* animals[10];

	for (size_t i = 0; i < 5; i++)
		animals[i] = new Cat('[' + itoString(i) + ']' + " Cat");
	
	for (size_t i = 5; i < 10; i++)
		animals[i] = new Dog('[' + itoString(i) + ']' + " Dog");

	for (size_t i = 0; i < 10; i++)
		delete animals[i];

	

	return (0);
}
