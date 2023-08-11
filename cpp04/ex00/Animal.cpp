#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Generic Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &original)
{
	this->type = original.type;
}

Animal &Animal::operator=(const Animal &original)
{
	this->type = original.type;
	return (*this);
}

void Animal::makeSound()
{
	std::cout << "*Generic Animal Sound*" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Generic Animal distructor called" << std::endl;
}
