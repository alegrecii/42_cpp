#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &original);
	FragTrap	&operator=(const FragTrap &original);
	void	highFivesGuys();
	void	attack(const std::string &target) override;
	~FragTrap();
};

#endif
