#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(Cat const &original);
	~Cat();
	Cat	&operator=(const Cat &original);
	void makeSound() const override;
};


#endif
