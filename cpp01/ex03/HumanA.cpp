#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << name << " is dying" << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanA::attack()
{
	std::cout << this->name << " is attacking with " << this->weapon.getType() << std::endl;
}
