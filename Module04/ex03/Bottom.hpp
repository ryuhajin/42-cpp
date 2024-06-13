#ifndef BOTTOM_HPP
# define BOTTOM_HPP

#include "AMateria.hpp"
#include <string>

class Bottom
{
private:
	AMateria* bottom[4];
public:
	Bottom();
	Bottom(const Bottom& in);
	Bottom& operator=(const Bottom& in);
	~Bottom();

	void ontheBottom (AMateria* materia);
};

#endif