#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap Gabbo("Gabbo");
	DiamondTrap Ale("Ale");

	Gabbo.attack("Ale");
	Ale.takeDamage(30);
	Ale.beRepaired(30);
	Ale.whoAmI();
	Gabbo.whoAmI();
	return (0);
}
