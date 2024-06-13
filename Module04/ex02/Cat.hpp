#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const std::string& in_string);
	Cat(const Cat& in);
	Cat& operator=(const Cat& in);
	~Cat();

	void	makeSound(void) const;
	Brain* 	getBrain(void);
	void 	setBrain (const std::string& idea, int i);
};

#endif
