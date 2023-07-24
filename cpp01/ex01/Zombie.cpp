#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " died " << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzZ..." << std::endl;
}

void	Zombie::nameIt(std::string name)
{
	this->name = name;
}
