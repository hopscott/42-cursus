/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:45:22 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:45:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
WrongAnimal::WrongAnimal( void )
{
	_type = "WrongAnimal";

	std::cout << _type << " - WrongAnimal Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	_type = src._type;

	std::cout << _type << " - WrongAnimal Copy Constructor called" << std::endl;

	return;
}

// Destructor
WrongAnimal::~WrongAnimal( void )
{
	std::cout << _type << " - WrongAnimal Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
WrongAnimal &	WrongAnimal::operator=(const WrongAnimal & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << _type << " - WrongAnimal Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	WrongAnimal::getType(void) const
{
	return _type;
}

void				WrongAnimal::makeSound(void) const
{
	std::cout << "*Weird grumbling mixed WrongAnimal noises*" << std::endl;
}

