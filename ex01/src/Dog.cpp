#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "[Dog]: default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	this->_type = other._type;
	this->_brain = other._brain;
	std::cout << "[Dog]: copy constructor called." << std::endl;
}

Dog&
Dog::operator=(const Dog& other)
{
	this->_type = other._type;
	this->_brain = other._brain;
	std::cout << "[Dog]: copy assignment called." << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "[Dog]: destructor called." << std::endl;
}

void
Dog::makeSound() const
{
	std::cout << "[Dog]: woof." << std::endl;
}

void
Dog::addIdea(const std::string& idea)
{
	this->_brain->addIdea(idea);
}

void
Dog::printIdeas() const
{
	std::cout << std::endl;
	this->_brain->printIdeas();
	std::cout << std::endl;
}
