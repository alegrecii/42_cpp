#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	//_name = "unknown scavtrap";
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdamage = 20;
	std::cout << "Named ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energypoints == 0)
		std::cout << _name <<" has no more energy points!" << std::endl;
	else if (_hitpoints == 0)
		std::cout << _name <<" is dead!" << std::endl;
	else
		{
			_energypoints--;
			std::cout << "ScavTrap "<< _name << " attacks " << target << ", causing " << _attackdamage << " damage!" << std::endl;
		}
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
