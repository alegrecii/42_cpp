#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";

}

Dog::Dog(Dog const &original) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = original.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
	this->type = original.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof"<<std::endl;
}
