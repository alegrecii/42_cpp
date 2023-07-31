#include <iostream>
#ifndef WEAPON_HPP
# define WEAPON_HPP
class Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	void	setType(std::string type);
	std::string const	&getType();
};

#endif
