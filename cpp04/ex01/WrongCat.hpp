#ifndef WCAT_HPP
# define WCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(WrongCat const &original);
	~WrongCat();
	WrongCat	&operator=(const WrongCat &original);
	void makeSound() const;
};


#endif
