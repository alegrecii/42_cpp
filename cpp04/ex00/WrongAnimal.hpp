#ifndef WANIMAL_HPP
# define WANIMAL_HPP
#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &original);
	virtual ~WrongAnimal();
	WrongAnimal	&operator=(const WrongAnimal &original);

	void	makeSound() const;
	std::string		getType() const;
};

#endif
