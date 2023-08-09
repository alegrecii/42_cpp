#include "ClapTrap.hpp"

int	main()
{
	ClapTrap unk;
	ClapTrap Lisa("Lisa");
	ClapTrap Lisa2(Lisa);
	ClapTrap Ale("Ale");

	unk.attack("pietro");

	for (size_t i = 0; i < 13; i++)
	{
		Lisa.takeDamage(1);
	}
	Lisa.attack("Ale");
	Ale.takeDamage(0);
	for (size_t i = 0; i < 13 ; i++)
	{
		Ale.attack("Andre");
	}
	Lisa2.attack("pietro");
	return (0);
}
