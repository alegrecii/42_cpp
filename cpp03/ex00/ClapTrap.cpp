#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_hitpoints = 10;
	_energypoints = 10;
	_attackdamage = 0;
	_name = "unknown claptrap";
	std::cout << "Default construtor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_hitpoints = 10;
	_energypoints = 10;
	_attackdamage = 0;
	this->_name = name;
	std::cout << "Named construtor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	std::cout << "Copy construtor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
	this->_hitpoints = original._hitpoints;
	this->_energypoints = original._energypoints;
	this->_attackdamage = original._attackdamage;
	this->_name = original._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energypoints == 0)
		std::cout << _name <<" has no more energy points!" << std::endl;
	else if (_hitpoints == 0)
		std::cout << _name <<" is dead!" << std::endl;
	else
		{
			_energypoints--;
			std::cout << "ClapTrap "<< _name << " attacks " << target << ", causing " << _attackdamage << " damage!" << std::endl;
		}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints == 0)
		std::cout << "Stop it's already dead!"<< std::endl;
	else if (_hitpoints >= amount)
	{
		_hitpoints -= amount;
		std::cout << _name << " took " << amount << " damage"<< std::endl;
	}
	else
	{
		_hitpoints = 0;
		std::cout << _name << "died after taking " << amount << " damage!"<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energypoints == 0)
		std::cout << _name <<" has no more energy points!" << std::endl;
	else if (_hitpoints == 0)
		std::cout << _name <<" is dead!" << std::endl;
	else
		{
			_energypoints--;
			std::cout << "ClapTrap "<< _name << " repairs itself " << amount << " hitpoints!" << std::endl;
		}
}
