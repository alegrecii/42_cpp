#include "ScavTrap.hpp"

int	main()
{
	ScavTrap unk;
	ScavTrap Lisa("Lisa");
	ScavTrap Lisa2(Lisa);
	ScavTrap Ale("Ale");

	unk.attack("Lisa");
	Lisa.takeDamage(20);
	Lisa.guardGate();
	Lisa2.attack("Ale");
	Ale.takeDamage(20);
	Ale.beRepaired(20);

	return (0);
}
