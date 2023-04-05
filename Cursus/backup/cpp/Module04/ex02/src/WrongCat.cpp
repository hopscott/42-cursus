/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:45:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
WrongCat::WrongCat( void )
{
	_type = "WrongCat";

	std::cout << _type << " - WrongCat Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
WrongCat::WrongCat( WrongCat const & src )
{
	_type = src._type;

	std::cout << _type << " - WrongCat Copy Constructor called" << std::endl;

	return;
}

// Destructor
WrongCat::~WrongCat( void )
{
	std::cout << _type << " - WrongCat Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
WrongCat &	WrongCat::operator=(const WrongCat & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << _type << " - WrongCat Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &	WrongCat::getType(void) const
{
	return _type;
}

void				WrongCat::makeSound(void) const
{
	std::cout << "*MEOW*" << std::endl;
}

