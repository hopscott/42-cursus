/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:04 by swillis           #+#    #+#             */
/*   Updated: 2023/04/05 21:57:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Data::Data( void )
: _a(0), _b(0), _c(0)
{
	return;
}

// Parametric Constructor
Data::Data( const int a, const int b, const int c )
: _a(a), _b(b), _c(c)
{
	return;
}

// Copy Constructor
Data::Data( Data const & src )
: _a(src._a), _b(src._b), _c(src._c)
{
	return;
}

// Destructor
Data::~Data( void )
{
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
