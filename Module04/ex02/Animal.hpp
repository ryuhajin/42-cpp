#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string& in_type);
	Animal(const Animal& in);
	virtual	~Animal();

	Animal& operator=(const Animal& in);

	virtual	void makeSound(void) const = 0;
	const std::string& getType(void) const;
	void	setType(const std::string& in_type);
};

#endif
