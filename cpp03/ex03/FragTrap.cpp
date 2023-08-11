#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	//_name = "unknown FragTrap";
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "Named FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (_energypoints == 0)
		std::cout << _name <<" has no more energy points!" << std::endl;
	else if (_hitpoints == 0)
		std::cout << _name <<" is dead!" << std::endl;
	else
		{
			_energypoints--;
			std::cout << "FragTrap "<< _name << " attacks " << target << ", causing " << _attackdamage << " damage!" << std::endl;
		}
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is asking for a high five!" << std::endl;
}
