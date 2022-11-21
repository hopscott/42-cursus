/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/21 01:54:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Converter::Converter( void )
{
	std::cout << "Converter Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Converter::Converter( Converter const & src )
{
	(void)src;
	
	std::cout << "Converter Copy Constructor called" << std::endl;

	return;
}

// Destructor
Converter::~Converter( void )
{
	std::cout << "Converter Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Converter &	Converter::operator=(const Converter & rhs)
{
	(void)rhs;

	std::cout << "Converter Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
