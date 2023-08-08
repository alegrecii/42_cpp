#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
class ClapTrap
{
private:
	int			_hitpoints;
	int			_energypoints;
	int			_attackdamage;
	std::string	name;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &original);
	ClapTrap	&operator=(const ClapTrap &original);
	~ClapTrap();
};

#endif
