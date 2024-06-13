# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "Dog.hpp"

# include <iostream>
# include <string>

void	check_leak(void)
{
	system("leaks ex00");
}

int main(void)
{
	atexit(check_leak);

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << "=========== WrongAnimal / WrongCat ===========" << '\n' << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	meta2->makeSound();

	std::cout << std::endl;

	delete meta2;
	delete k;

	return (0);
}
