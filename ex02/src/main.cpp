#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* a[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		if (i % 2)
			a[i] = new Dog();
		else
			a[i] = new Cat();
		for (int j = 0; j < i; j++)
		{
			if (i % 2)
				static_cast<Dog*>(a[i])->addIdea("I'm a dog");
			else
				static_cast<Cat*>(a[i])->addIdea("I'm a cat");
		}
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		if (i % 2)
			static_cast<Dog*>(a[i])->printIdeas();
		else
			static_cast<Cat*>(a[i])->printIdeas();
	}

	Cat cat = *static_cast<Cat*>(a[2]);
	cat.addIdea("I want to kill humans");

	static_cast<Cat*>(a[2])->printIdeas();
	cat.printIdeas();

	for(int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		delete a[i];
	}
	std::cout << std::endl;

	return 0;
}
