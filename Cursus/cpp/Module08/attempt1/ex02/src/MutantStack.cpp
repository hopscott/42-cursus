/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/03 20:03:10 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
MutantStack::MutantStack( void )
: _maxsize(0), _idx(0), _arr(NULL)
{
	return;
}

// Parametric Constructor

// Copy Constructor
MutantStack::MutantStack( MutantStack const & src )
: _maxsize(src._maxsize), _idx(src._idx), _arr(NULL)
{
	if (_maxsize > 0)
	{
		_arr = 	new int[_maxsize];
		
		for (unsigned int i=0; i<_maxsize; ++i)
		{
			_arr[i] = src._arr[i];
		}
	}
	return;
}

// Destructor
MutantStack::~MutantStack( void )
{
	if (_arr)
	{
		delete [] _arr;
	}
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
MutantStack &	MutantStack::operator=(const MutantStack & rhs)
{
	if (this != &rhs)
	{
		_maxsize = rhs._maxsize;
		_idx = rhs._idx;
		_arr = 	NULL;

		if (_maxsize > 0)
		{
			_arr = 	new int[_maxsize];
			
			for (unsigned int i=0; i<_maxsize; ++i)
			{
				_arr[i] = rhs._arr[i];
			}
		}
	}

	return (*this);
}

// --------------- FUNCTIONS ---------------

// Member functions
