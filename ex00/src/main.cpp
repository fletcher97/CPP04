#include <iostream>

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void
testAnimal(const Animal* a)
{
	std::cout << std::endl;
	std::cout << a->getType() << std::endl;
	a->makeSound();
	std::cout << std::endl;
}

void
testAnimal(const WrongAnimal* a)
{
	std::cout << std::endl;
	std::cout << a->getType() << std::endl;
	a->makeSound();
	std::cout << std::endl;
}


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();

	testAnimal(meta);
	testAnimal(i);
	testAnimal(j);
	testAnimal(a);
	testAnimal(b);

	delete b;
	delete a;
	delete i;
	delete j;
	delete meta;
	return 0;
}
