/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Ice::Ice(void)
: AMateria("ice")
{

	return;
}

// Copy Constructor
Ice::Ice( Ice const & src )
: AMateria("ice")
{
	(void)src;
	return;
}

// Destructor
Ice::~Ice( void )
{	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Ice &	Ice::operator=(const Ice & rhs)
{

	if (this != &rhs)
	{
		_type = "ice";
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

std::string const &		Ice::getType(void) const
{
	return _type;
}

Ice*					Ice::clone(void) const
{
	return new Ice(*this);
}

void					Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
