#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
	this->type = original.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
	this->type = original.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Wrong Animal Sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal distructor called" << std::endl;
}
