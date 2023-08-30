#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Wrong Cat constructor called" << std::endl;
	this->type = "Wrong Cat";
}

WrongCat::WrongCat(WrongCat const &original) : WrongAnimal()
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	this->type = original.type;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
	this->type = original.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meooow"<<std::endl;
}
