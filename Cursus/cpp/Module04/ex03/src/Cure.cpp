/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Cure::Cure(void)
: AMateria("cure")
{

	return;
}

// Copy Constructor
Cure::Cure( Cure const & src )
: AMateria(src._type)
{

	return;
}

// Destructor
Cure::~Cure( void )
{	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Cure &	Cure::operator=(const Cure & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

std::string const &		Cure::getType(void) const
{
	return _type;
}

Cure*					Cure::clone(void) const
{
	return new Cure();
}

void					Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
