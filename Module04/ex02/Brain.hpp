#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& in);
	Brain& operator=(const Brain& in);
	~Brain();

	const std::string& getIdeas(int i) const;
	void setIdeas (const std::string& idea, int i);
};

#endif
