#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "[Dog]: default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal()
{
	this->_type = other._type;
	std::cout << "[Dog]: constructor called." << std::endl;
}

Dog&
Dog::operator=(const Dog& other)
{
	this->_type = other._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog]: destructor called." << std::endl;
}

void
Dog::makeSound() const
{
	std::cout << "[Dog]: woof." << std::endl;
}
