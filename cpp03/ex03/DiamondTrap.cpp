#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_hitpoints = FragTrap::_hitpoints;
	_energypoints = 50;
	_attackdamage = FragTrap::_attackdamage;
	_name = "unknown DiamondTrap";
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitpoints = FragTrap::_hitpoints;
	_energypoints = ScavTrap::_energypoints;
	_attackdamage = FragTrap::_attackdamage;
	std::cout << "Named DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout<< "DiamondTrap name: " << _name << ". Claptrap name: " << ClapTrap::_name << std::endl;
}
