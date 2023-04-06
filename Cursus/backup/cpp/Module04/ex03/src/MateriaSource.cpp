/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
MateriaSource::MateriaSource(void)
: _last_idx(-1)
{

	for (int i=0; i<MAX_MATERIAS; ++i)
	{
		_materias[i] = NULL;
	}

	return;
}

// Copy Constructor
MateriaSource::MateriaSource( MateriaSource const & src )
: _last_idx(src._last_idx)
{
	for (int i=0; i<MAX_MATERIAS; ++i)
	{
		_materias[i] = NULL;
	}

	for (int i=0; i<=src._last_idx; ++i)
	{
		_materias[i] = src._materias[i]->clone();
	}

	return;
}

// Destructor
MateriaSource::~MateriaSource( void )
{	
	for (int i=0; i<=_last_idx; ++i)
	{
		delete _materias[i];
	}

	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
MateriaSource &	MateriaSource::operator=(const MateriaSource & rhs)
{

	if (this != &rhs)
	{

		for (int i=0; i<=_last_idx; ++i)
		{
			delete _materias[i];
		}

		_last_idx = rhs._last_idx;

		for (int i=0; i<=_last_idx; ++i)
		{
			*_materias[i] = *rhs._materias[i];
		}
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

void		MateriaSource::learnMateria(AMateria* materia)
{
	
	if (_last_idx + 1 < MAX_MATERIAS)
	{
		++_last_idx;
		_materias[_last_idx] = materia;

		std::cout << "MateriaSource [" << _last_idx << "] " << materia->getType() << " learning" << std::endl;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{

	if (_last_idx == -1)
		return 0;

	// search for type in slots
	for (int i=0; i<=_last_idx; ++i)
	{
		if (_materias[i]->getType() == type)
		{
			std::cout << "MateriaSource [" << i << "] " << _materias[i]->getType() << " creating" << std::endl;
			return _materias[i]->clone();
		}
	}

	// type unknown
	return 0;

}
