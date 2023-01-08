#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
	Animal* meta = new Animal();
	Dog* i = new Dog();
	Cat* j = new Cat();

	const Animal* meta2 = new Animal(*meta);
	const Dog* k = new Dog(*i);
	const Cat* l = new Cat(*j);

	const WrongAnimal* a = new WrongAnimal();
	const WrongCat* b = new WrongCat();

	const WrongAnimal* c = new WrongAnimal(*a);
	const WrongCat* d = new WrongCat(*b);

	testAnimal(meta);
	testAnimal(meta2);

	testAnimal(i);
	testAnimal(j);

	testAnimal(k);
	testAnimal(l);

	testAnimal(a);
	testAnimal(b);

	testAnimal(c);
	testAnimal(d);

	*meta = *meta2;
	*i = *k;
	*j = *l;

	std::cout << std::endl;

	delete d;
	delete c;

	delete b;
	delete a;

	delete l;
	delete k;

	delete j;
	delete i;

	delete meta;

	return 0;
}
