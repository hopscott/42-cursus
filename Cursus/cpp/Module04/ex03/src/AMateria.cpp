/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
AMateria::AMateria(std::string const & type)
: _type(type)
{

	return;
}

// Copy Constructor
AMateria::AMateria( AMateria const & src )
: _type(src._type)
{

	return;
}

// Destructor
AMateria::~AMateria( void )
{	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
AMateria &	AMateria::operator=(const AMateria & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

std::string const &		AMateria::getType(void) const
{
	return _type;
}

void					AMateria::use(ICharacter& target)
{
	std::cout << "* generic materia gloop bounces off " << target.getName() << " *" << std::endl;
}
