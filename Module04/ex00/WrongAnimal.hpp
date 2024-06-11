#ifndef WRONGANIMAL_CPP
# define WRONGANIMAL_CPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const std::string& in_type);
	WrongAnimal(const WrongAnimal& in);

	WrongAnimal& operator=(const WrongAnimal& in);
	
	~WrongAnimal();

	void	makeSound(void) const;
	const std::string& getType(void) const;
	void	setType(const std::string& in_type);
};

#endif
