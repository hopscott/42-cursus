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
: _name(name)
{
	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		_inventory[i] = NULL;
	}

	return;
}

// Copy Constructor
Character::Character( Character const & src )
: _name(src._name)
{
	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		_inventory[i] = src._inventory[i];
	}

	return;
}

// Destructor
Character::~Character( void )
{	
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
			delete _inventory[i];
		}

		for (int i=0; i<MAX_INVENTORY; ++i)
		{
			_inventory[i] = rhs._inventory[i];
		}
		
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

std::string const &		getName() const;
		void					equip(AMateria* m);
		void					unequip(int idx);
		void					use(int idx, ICharacter& target);
