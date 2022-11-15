/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:42:38 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Dog::Dog( void )
{
	_type = "Dog";

	std::cout << _type << " - Dog Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Dog::Dog( Dog const & src )
{
	_type = src._type;

	std::cout << _type << " - Dog Copy Constructor called" << std::endl;

	return;
}

// Destructor
Dog::~Dog( void )
{
	std::cout << _type << " - Dog Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Dog &	Dog::operator=(const Dog & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << _type << " - Dog Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	Dog::getType(void) const
{
	return _type;
}

void				Dog::makeSound(void) const
{
	std::cout << "*WOOF*" << std::endl;
}

