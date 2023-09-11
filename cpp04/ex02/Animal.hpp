#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &original);
	virtual ~Animal();
	Animal	&operator=(const Animal &original);

	virtual void	makeSound() const = 0;
	std::string		getType() const;
};

#endif
