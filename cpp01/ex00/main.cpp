#include "Zombie.hpp"

int	main()
{
	Zombie *silvio = newZombie("silvio");
	silvio->announce();
	randomChump("random");
	silvio->announce();
	silvio->announce();
	delete (silvio);
}
