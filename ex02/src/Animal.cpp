#include <iostream>

#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "[Animal]: default constructor called." << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "[Animal]: copy constructor called." << std::endl;
}

Animal&
Animal::operator=(const Animal& other)
{
	this->_type = other._type;
	std::cout << "[Animal]: copy assignment called." << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal]: destructor called." << std::endl;
}

std::string
Animal::getType() const
{
	return this->_type;
}
