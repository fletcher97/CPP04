#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "[Cat]: default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	this->_type = other._type;
	std::cout << "[Cat]: constructor called." << std::endl;
}

Cat&
Cat::operator=(const Cat& other)
{
	this->_type = other._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat]: destructor called." << std::endl;
}

void
Cat::makeSound() const
{
	std::cout << "[Cat]: meow." << std::endl;
}
