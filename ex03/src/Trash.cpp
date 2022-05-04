#include "Trash.hpp"

#include <cstddef>
#include <iostream>


Trash::Node::Node() : _content(NULL), _next(NULL)
{}

Trash::Node::Node(AMateria* content) : _content(content), _next(NULL)
{}

Trash::Node::Node(const Trash::Node& other) : _content(other._content), _next(other._next)
{}

Trash::Node& Trash::Node::operator=(const Trash::Node& other)
{
	this->_content = other._content;
	this->_next = other._next;
	return *this;
}


Trash::Node::~Node()
{
	delete this->_next;
	delete this->_content;
}

bool Trash::Node::hasNext() const
{
	return this->_next != NULL;
}

Trash::Node* Trash::Node::next() const
{
	return this->_next;
}

void Trash::Node::addNext(Trash::Node* next)
{
	this->_next = next;
}

Trash::Trash() : _head(NULL)
{}

Trash::Trash(const Trash& other) : _head(other._head)
{}

Trash& Trash::operator=(const Trash& other)
{
	this->_head = other._head;
	return *this;
}

Trash::~Trash()
{
	delete this->_head;
}

void Trash::add(AMateria *elem)
{
	if (!this->_head)
	{
		this->_head = new Trash::Node(elem);
		return;
	}
	Node* n = this->_head;
	while (n->hasNext())
	{
		n = n->next();
	}
	n->addNext(new Trash::Node(elem));
}
