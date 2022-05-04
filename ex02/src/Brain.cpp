#include <iostream>

#include "Brain.hpp"

Brain::Brain() : _curr_idea(0)
{
	std::cout << "[Brain]: default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < other._curr_idea; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
	this->_curr_idea = other._curr_idea;
	std::cout << "[Brain]: copy constructor called." << std::endl;
}

Brain&
Brain::operator=(const Brain& other)
{
	for (int i = 0; i < other._curr_idea; i++)
	{
		if (other._ideas[i].empty())
			break;
		this->_ideas[i] = other._ideas[i];
	}
	this->_curr_idea = other._curr_idea;
	std::cout << "[Brain]: copy assignment called." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain]: destructor called." << std::endl;
}

int
Brain::getCurrIdea() const
{
	return this->_curr_idea;
}

void
Brain::printIdeas() const
{
	for (int i = 0; i < this->_curr_idea; i++)
	{
		std::cout << "[Brain (" << i << ")]: " << this->_ideas[i] << std::endl;
	}

}

void
Brain::addIdea(const std::string& idea)
{
	if (this->_curr_idea == 100)
	{
		std::cout << "[Brain]: full of ideas." << std::endl;
		return;
	}
	//std::cout << "Adding idea at " << this->_curr_idea << std::endl;
	this->_ideas[this->_curr_idea++] = idea;
}
