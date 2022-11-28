/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 21:39:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Data::Data( void )
: _maxsize(0), _idx(0), _arr(NULL)
{
	return;
}

// Parametric Constructor
Data::Data( const unsigned int N )
: _maxsize(N), _idx(0), _arr(NULL)
{
	if (_maxsize > 0)
	{
		_arr = 	new int[_maxsize];
		
		for (unsigned int i=0; i<_maxsize; ++i)
		{
			_arr[i] = 0;
		}
	}

	return;
}

// Copy Constructor
Data::Data( Data const & src )
: _maxsize(src._maxsize), _idx(src._idx), _arr(NULL)
{
	if (_n > 0)
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
Data::~Data( void )
{
	if (_arr)
	{
		delete [] _arr;
	}
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Data &	Data::operator=(const Data & rhs)
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
void		addNumber(int n)
{
	if ((!_arr) || (_pos + 1 >= _N))
		throw std::exception();
	
	_arr[_pos] = n;
	++_pos;
}

int			shortestSpan(void)
{
	std::sort()
}

int			longestSpan(void)
{
	
}

template <typename C>
void		addIterNumbers(typename C::const_iterator it)
{
	while (it && *it)
	{
		addNumber(*it++);
	}
}
