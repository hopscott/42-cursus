/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 15:05:00 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <cmath>

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define RESET		"\x1b[0m"

template< typename T >
class Array {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Array<T>( void ) : _n(0), _arr(NULL)
		{
			return;
		}

		// Parametric Constructor
		Array<T>( const unsigned int n ): _n(n), _arr(NULL)
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
		Array<T>( Array<T> const & src ): _n(src._n), _arr(NULL)
		{
			if (_n > 0)
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
		~Array<T>( void )
		{
			if (_arr)
			{
				delete [] _arr;
			}
			
			return;
		}
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Array<T> &	operator=(const Array<T> & rhs)
		{

			if (this != &rhs)
			{
				_n = rhs._n;
				_arr = 	NULL;

				if (_n > 0)
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

		// Subscript Operator Overload
		T &	operator[](const unsigned int pos)
		{
			if ((!_arr) || (pos >= _n))
				throw std::exception();

			return _arr[pos];
		}

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		unsigned int	size( void ) const
		{
			return _n;
		}

	private:

		unsigned int	_n;
		T *				_arr;

};

#endif
