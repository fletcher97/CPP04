#include "MateriaSource.hpp"

#include <cstddef>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_inv[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i] != NULL)
			this->_inv[i] = other._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}
}

MateriaSource&
MateriaSource::operator=(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
		if (other._inv[i] != NULL)
			this->_inv[i] = other._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
	}
}

void
MateriaSource::learnMateria(AMateria* materia)
{
	int i;
	for(i = 0; i < 4 && this->_inv[i] != NULL; i++);
	if (i < 4)
		this->_inv[i] = materia;
}

AMateria*
MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i]->getType().compare(type) == 0)
			return this->_inv[i]->clone();
	}
	return NULL;
}
