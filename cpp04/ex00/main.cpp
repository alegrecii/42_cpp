#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

const WrongAnimal* w = new WrongCat();
std::cout << w->getType() << " " << std::endl;
w->makeSound();

const WrongCat* z = new WrongCat();
std::cout << z->getType() << " " <<std::endl;
z->makeSound();

delete meta;
delete i;
delete j;
delete w;
delete z;

return (0);
}
