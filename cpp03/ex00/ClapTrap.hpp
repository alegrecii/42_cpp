#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
class ClapTrap
{
private:
	int			_hitpoints;
	int			_energypoints;
	int			_attackdamage;
	std::string	_name;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &original);
	ClapTrap	&operator=(const ClapTrap &original);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif
