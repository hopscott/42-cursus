/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:21:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
AAnimal::AAnimal( void )
{
	_type = "AAnimal";

	std::cout << _type << " - AAnimal Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
AAnimal::AAnimal( AAnimal const & src )
{
	_type = src._type;

	std::cout << _type << " - AAnimal Copy Constructor called" << std::endl;

	return;
}

// Destructor
AAnimal::~AAnimal( void )
{
	std::cout << _type << " - AAnimal Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
AAnimal &	AAnimal::operator=(const AAnimal & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << _type << " - AAnimal Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	AAnimal::getType(void) const
{
	return _type;
}
