#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &original) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = original.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
	this->type = original.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meooow"<<std::endl;
}
