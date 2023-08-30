#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
	std::cout<<"--------Deep Copy test start-------"<< std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal *k = new Dog();
	*k = *j;
	delete j;
	delete i;
	delete k;
	std::cout<<"--------Deep Copy test over--------"<< std::endl;
	std::cout<<"--------Mix Array test start-------"<< std::endl;
	Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	animals[3]->makeSound();

	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout<<"--------Mix Array test over--------"<< std::endl;

return 0;
}
