#include "DiamondTrap.hpp"

int	main()
{
	FragTrap unk;
	FragTrap Lisa("Lisa");
	FragTrap Lisa2(Lisa);
	FragTrap Ale("Ale");

	unk.attack("Lisa");
	Lisa.takeDamage(30);
	Lisa.highFivesGuys();
	Lisa2.attack("Ale");
	Ale.takeDamage(30);
	Ale.beRepaired(20);

	return (0);
}
