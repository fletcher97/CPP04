#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "[WrongCat]: default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
	this->_type = other._type;
	std::cout << "[WrongCat]: constructor called." << std::endl;
}

WrongCat&
WrongCat::operator=(const WrongCat& other)
{
	this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]: destructor called." << std::endl;
}

void
WrongCat::makeSound() const
{
	std::cout << "[WrongCat]: meow." << std::endl;
}
