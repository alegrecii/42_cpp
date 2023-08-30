#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(Dog const &original);
	~Dog();
	Dog	&operator=(const Dog &original);
	void makeSound() const override;
};


#endif
