/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/05 18:07:05 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Span::Span( void )
: _maxsize(0), _idx(0), _arr(NULL)
{
	return;
}

// Parametric Constructor
Span::Span( const unsigned int N )
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
Span::Span( Span const & src )
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
Span::~Span( void )
{
	if (_arr)
	{
		delete [] _arr;
	}
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Span &	Span::operator=(const Span & rhs)
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
void		Span::addNumber(int n)
{
	if ((!_arr) || (_idx >= _maxsize))
		throw std::exception();
	
	_arr[_idx] = n;
	++_idx;
}

size_t		Span::shortestSpan(void)
{
	if ((!_arr) || (_maxsize < 2))
		throw std::exception();

	std::vector<int>	v;
	size_t				range = std::numeric_limits<size_t>::max();
	size_t				newRange;
	
    std::copy(&_arr[0], &_arr[_idx], std::back_inserter(v));
	std::sort(v.begin(), v.end());

	for (std::size_t i=0; i!=v.size()-1; ++i) {

		newRange = v[i+1] - v[i];
		if (std::less<int>(newRange, range))
			range = newRange;
	}
	
	return range;
}

size_t		Span::longestSpan(void)
{
	if ((!_arr) || (_maxsize < 2))
		throw std::exception();

	size_t				range = 0;
	std::vector<int> 	v;

    std::copy(&_arr[0], &_arr[_idx], std::back_inserter(v));
	std::sort(v.begin(), v.end());

	range = v.back() - v.front();

	return range;
}

template <typename C>
void		Span::addIterNumbers(typename C::const_iterator& begin, typename C::const_iterator& end)
{
	for (typename C::const_iterator& it=begin; it!=end; ++it)
	{
		addNumber(*it);
	}
}
