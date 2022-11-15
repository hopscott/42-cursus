/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:40:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Animal::Animal( void )
{
	_type = "Animal";

	std::cout << _type << " - Animal Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Animal::Animal( Animal const & src )
{
	_type = src._type;

	std::cout << _type << " - Animal Copy Constructor called" << std::endl;

	return;
}

// Destructor
Animal::~Animal( void )
{
	std::cout << _type << " - Animal Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Animal &	Animal::operator=(const Animal & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << _type << " - Animal Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	Animal::getType(void) const
{
	return _type;
}

void				Animal::makeSound(void) const
{
	std::cout << "*Weird grumbling mixed animal noises*" << std::endl;
}

