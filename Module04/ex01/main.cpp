# include "Animal.hpp"
# include "Brain.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

void	check_leak(void)
{
	system("leaks ex01");
}

const std::string itoString(int num)
{
	std::stringstream itoS;

	itoS << num;

	return (itoS.str());
}

int main(void)
{
	atexit(check_leak);

	Animal* animals[10];

	//animals array delete test

	for (size_t i = 0; i < 5; i++)
		animals[i] = new Cat('[' + itoString(i) + ']' + " Cat");
	
	for (size_t i = 5; i < 10; i++)
		animals[i] = new Dog('[' + itoString(i) + ']' + " Dog");

	for (size_t i = 0; i < 10; i++)
		delete animals[i];


	//cat brain test

	Cat* cats[3];

	for (size_t i = 0; i < 3; i++)
	{
		cats[i] = new Cat('[' + itoString(i) + ']' + " Cat");
	}
	
	std::cout << "Cat [0] brain ideas : " << cats[0]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;

	std::cout << "Cat [1] brain ideas : " << cats[1]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;

	std::cout << "Cat [0] brain setBrain: " << "I'm hungry...." << '\n';

	cats[0]->setBrain("I'm hungry....", 0);

	std::cout << "Cat [0] brain ideas : " << cats[0]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;

	*cats[1] = *cats[0];

	std::cout << "Cat [1] brain ideas : " << cats[1]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;


	std::cout << "Cat [1] brain setBrain : " << "I'm CoooooooooL 😎" << '\n';

	cats[1]->setBrain("I'm CoooooooooL 😎", 0);

	std::cout << "Cat [1] brain ideas : " << cats[1]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;

	std::cout << "Cat [0] brain ideas : " << cats[0]->getBrain()->getIdeas(0)
	<< '\n' << std::endl;

	for (size_t i = 0; i < 3; i++)
	{
		delete cats[i];
	}

	return (0);
}
