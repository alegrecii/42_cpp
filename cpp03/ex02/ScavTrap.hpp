#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &original);
	ScavTrap	&operator=(const ScavTrap &original);
	void	guardGate();
	void	attack(const std::string &target) override;
	~ScavTrap();
};

#endif
