#include "Weapon.hpp"
Weapon::Weapon()
{
	this->type = "hands";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	return ;
}

void	Weapon::setType(std::string	type)
{
	this->type = type;
}

const std::string	&Weapon::getType()
{
	return(this->type);
}
