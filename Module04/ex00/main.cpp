# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include <iostream>
# include <string>

int main(void)
{
	const Animal * animal = new Animal();
	Animal * cat = new Cat();
	Animal * dog = new Dog();

	*dog = *animal;
	std::cout << dog->getType();

	cat = dog;
	cat->getType();

	return (0);
}

// int main(void)
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
	
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
	
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	return (0);
// }
