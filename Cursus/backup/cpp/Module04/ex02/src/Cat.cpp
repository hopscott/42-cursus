/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 22:03:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Cat::Cat( void )
{
	_type = "Cat";
	_brain = new Brain();

	std::cout << _type << " - Cat Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Cat::Cat( Cat const & src )
{
	_type = src._type;
	_brain = new Brain(*src._brain);

	std::cout << _type << " - Cat Copy Constructor called" << std::endl;

	return;
}

// Destructor
Cat::~Cat( void )
{
	delete _brain;

	std::cout << _type << " - Cat Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Cat &	Cat::operator=(const Cat & rhs)
{

	if (this != &rhs)
	{
		_type = rhs._type;
		*_brain = *rhs._brain;
	}
	
	std::cout << _type << " - Cat Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

const std::string &		Cat::getType(void) const
{
	return _type;
}

void					Cat::makeSound(void) const
{
	std::cout << "*MEOW*" << std::endl;
}

const Brain*			Cat::getBrain(void) const
{
	return _brain;
}
