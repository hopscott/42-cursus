/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 02:31:41 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Cat::Cat( void )
: Animal()
{
	_type = "Cat"

	std::cout << "Cat (" << _type << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Cat::Cat( Cat const & src )
: Animal()
{
	_type = "Cat"

	std::cout << "Cat (" << _type << ") - Copy Constructor called" << std::endl;

	return;
}

// Destructor
Cat::~Cat( void )
{
	std::cout << "Cat (" << _type << ") - Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Cat &	Cat::operator=(const Cat & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
	}
	
	std::cout << "Cat (" << _type << ") - Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

std::string &	Cat::getType(void)
{
	return _type;
}

void			Cat::makeSound(void)
{
	std::cout << "*MEOW*" << std::endl;
}

