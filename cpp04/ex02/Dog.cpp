#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = "Woof woof woof";

}

Dog::Dog(Dog const &original) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this->brain = *original.brain;
	this->type = original.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &original)
{
	this->type = original.type;
	*this->brain = *original.brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof"<<std::endl;
}
