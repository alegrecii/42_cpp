#include "Weapon.hpp"
#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
private:
	Weapon		&weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	setWeapon(Weapon weapon);
	void	attack();
};

#endif
