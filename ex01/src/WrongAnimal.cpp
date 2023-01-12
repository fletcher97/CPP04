#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown")
{
	std::cout << "[WrongAnimal]: default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "[WrongAnimal]: constructor called." << std::endl;
}

WrongAnimal&
WrongAnimal::operator=(const WrongAnimal& other)
{
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal]: destructor called." << std::endl;
}

std::string
WrongAnimal::getType() const
{
	return this->_type;
}

void
WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal]: unrecognizable noise." << std::endl;
}
