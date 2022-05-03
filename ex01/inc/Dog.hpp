#if !defined(DOG_HPP)
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void makeSound() const;
	void addIdea(const std::string& idea);
	void printIdeas() const;
};

#endif // DOG_HPP
