#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap :virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &original);
	FragTrap	&operator=(const FragTrap &original);
	void	highFivesGuys();
	void	attack(const std::string &target);
	~FragTrap();
};

#endif
