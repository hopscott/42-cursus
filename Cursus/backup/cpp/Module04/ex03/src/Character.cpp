/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Character::Character( std::string const & name )
: _name(name), _droplst(NULL)
{

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		_inventory[i] = NULL;
	}

	return;
}

// Copy Constructor
Character::Character( Character const & src )
: _name(src._name), _droplst(NULL)
{

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		_inventory[i] = NULL;
	}

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
	}

	return;
}

// Destructor
Character::~Character( void )
{
	Node*	next;

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}

	while (_droplst)
	{
		delete _droplst->_drop_addr;
		next = _droplst->next;
		delete _droplst;
		_droplst = next;
	}

	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Character &	Character::operator=(const Character & rhs)
{

	if (this != &rhs)
	{
		_name = rhs._name;

		// During copy, the Materias of a Character must be deleted before 
		// the new ones are added to their inventory.

		for (int i=0; i<MAX_INVENTORY; ++i)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}

		for (int i=0; i<MAX_INVENTORY; ++i)
		{
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
		
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	Character::getName() const 
{
	return _name;
}

void				Character::equip(AMateria* materia)
{
	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		if (!_inventory[i])
		{
			std::cout << "Character [" << i << "] " << materia->getType() << " equipped" << std::endl;
			_inventory[i] = materia;
			return;
		}
	}
}

void				Character::unequip(int idx)
{
	// outside inventory
	if (idx<0 || idx>=MAX_INVENTORY)
		return;

	if (_inventory[idx])
	{
		std::cout << "Character [" << idx << "] " << _inventory[idx]->getType() << " dropped" << std::endl;
		_dropItem(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void				Character::use(int idx, ICharacter& target)
{
	// outside inventory
	if (idx<0 || idx>=MAX_INVENTORY)
		return;

	if (_inventory[idx])
	{
		std::cout << "Character [" << idx << "] " << _inventory[idx]->getType() << " used" << std::endl;
		_inventory[idx]->use(target);
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void				Character::_dropItem(AMateria* materia)
{
	Node*	tbd = new Node();

	// push front
	tbd->_drop_addr = materia;
	tbd->next = _droplst;
	_droplst = tbd; 
}
