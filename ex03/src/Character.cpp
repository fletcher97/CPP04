#include "Character.hpp"
#include "AMateria.hpp"

#include <cstddef>
#include <iostream>

Character::Character() : _name("No Name")
{
	for (int i = 0; i < 4; i++)
	{
		this->_inv[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inv[i] = NULL;
	}
}

Character::Character(std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inv[i] = NULL;
	}
}

Character::Character(const Character& other) : _name(other.getName())
{
	this->bin.clean();
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i] != NULL)
			this->_inv[i] = other._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}
}

Character&
Character::operator=(const Character& other)
{
	this->bin.clean();
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
		if (other._inv[i] != NULL)
			this->_inv[i] = other._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] != NULL)
		{
			delete this->_inv[i];
		}
	}
}

const std::string&
Character::getName() const
{
	return this->_name;
}

void
Character::equip(AMateria* m)
{
	int i;
	for (i = 0; i < 4 && this->_inv[i] != NULL; i++);
	if (i < 4)
		this->_inv[i] = m;
}

void
Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inv[idx] == NULL)
		return;
	bin.add(this->_inv[idx]);
	this->_inv[idx] = NULL;
}

void
Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inv[idx] == NULL)
		return;
	this->_inv[idx]->use(target);
}
