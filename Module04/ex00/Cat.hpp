#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string& in_string);
	Cat(const Cat& in);
	Cat& operator=(const Cat& in);
	~Cat();

	void	makeSound(void) const;
};

#endif
