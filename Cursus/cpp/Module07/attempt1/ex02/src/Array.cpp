/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 00:36:53 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Array::Array( void )
: _n(n), _arr(NULL)
{
	return;
}

// Parametric Constructor
Array::Array( const unsigned int n )
: _n(n), _arr(NULL)
{
	if (n > 0)
	{
		_arr = 	new T[_n];
		for (unsigned int i=0; i<_n; ++i)
		{
			_arr[i] = 0;
		}
	}

	return;
}

// Copy Constructor
Array::Array( Array const & src )
: _n(src._n), _arr(NULL)
{
	if (n > 0)
	{
		_arr = 	new T[_n];
		
		for (unsigned int i=0; i<_n; ++i)
		{
			_arr[i] = src._arr[i];
		}
	}
	
	return;
}

// Destructor
Array::~Array( void )
{
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Array &	Array::operator=(const Array & rhs)
{

	if (this != &rhs)
	{
		_n = rhs._n;
		_arr = 	NULL;

		if (n > 0)
		{
			_arr = 	new T[_n];
			
			for (unsigned int i=0; i<_n; ++i)
			{
				_arr[i] = rhs._arr[i];
			}
		}
	}

	return (*this);
}

// --------------- FUNCTIONS ---------------

// Member functions
