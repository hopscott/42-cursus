/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 18:02:08 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Data::Data( void )
: _a(0), _b(0), _c(0)
{
	std::cout << "Data Default Constructor called" << std::endl;
	
	return;
}

// Parametric Constructor
Data::Data( const int a, const int b, const int c )
: _a(a), _b(b), _c(c)
{
	std::cout << "Data Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Data::Data( Data const & src )
: _a(src._a), _b(src._b), _c(src._c)
{
	std::cout << "Data Copy Constructor called" << std::endl;

	return;
}

// Destructor
Data::~Data( void )
{
	std::cout << "Data Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Data &	Data::operator=(const Data & rhs)
{

	if (this != &rhs)
	{
		_a = rhs._a;
		_b = rhs._b;
		_c = rhs._c;
	}

	std::cout << "Data Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

int		Data::getA(void) const
{
	return _a;
}

int		Data::getB(void) const
{
	return _b;
}

int		Data::getC(void) const
{
	return _c;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Data const & rhs ) {

	o << "data (" << rhs.getA() << ", " << rhs.getB() << ", " << rhs.getC() << ")";
	return o;
}
