#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = original;
}

Brain &Brain::operator=(const Brain &original)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
