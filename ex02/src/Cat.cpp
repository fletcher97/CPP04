#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "[Cat]: default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal()
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << "[Cat]: copy constructor called." << std::endl;
}

Cat&
Cat::operator=(const Cat& other)
{
	this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	std::cout << "[Cat]: copy assignment called." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "[Cat]: destructor called." << std::endl;
}

void
Cat::makeSound() const
{
	std::cout << "[Cat]: meow." << std::endl;
}

void
Cat::addIdea(const std::string& idea)
{
	this->_brain->addIdea(idea);
}

void
Cat::printIdeas() const
{
	std::cout << std::endl;
	this->_brain->printIdeas();
	std::cout << std::endl;
}
