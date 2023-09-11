#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
		for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = "Meow meow meow";
}

Cat::Cat(Cat const &original) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this->brain = *original.brain;
	this->type = original.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &original)
{
	this->type = original.type;
	*this->brain = *original.brain;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meooow"<<std::endl;
}
