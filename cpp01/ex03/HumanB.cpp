#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	std::cout << name << " is dying" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " is attacking with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is attacking with hands" << std::endl;
}
