/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/10 18:40:31 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <cmath>

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define RESET		"\x1b[0m"

// https://www.stroustrup.com/except.pdf
// https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c

template< typename T, class A = std::allocator<T> >
class Vector {

	public:

		// --------------- MEMBER TYPES ---------------

		typedef T												value_type;
		typedef A												allocator_type;
		typedef size_t											size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename A::pointer								pointer;
		typedef typename A::const_pointer						const_pointer;
		
		// typedef std::iterator<T>								iterator;
		// typedef const std::iterator								const_iterator;
		// typedef std::reverse_iterator<iterator>					reverse_iterator;
		// typedef const std::reverse_iterator<const_iterator>		const_reverse_iterator;

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// https://stackoverflow.com/questions/2509499/how-to-use-stdallocator-in-my-own-container-class
	
		// Default Constructor
		Vector<T>( void )
		{
			_v = _alloc.allocate(1, 0);
			// _alloc.construct(_v, 0);
			return;
		}

		// Parametric Constructor
		Vector<T>( const unsigned int n )
		{
			(void)n;
			return;
		}

		// Copy Constructor
		Vector<T>( Vector<T> const & src )
		{
			(void)src;
			return;
		}
	
		// Destructor
		~Vector<T>( void )
		{
			return;
		}
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Vector<T> &	operator=(const Vector<T> & rhs)
		{
			if (this != &rhs)
			{
				return (*this);
			}

			return (*this);
		}


	// 	// --------------- MEMBER FUNCTIONS ---------------
	
	// 	assign;
	// 	get_allocator;
		
	// 	// --- Element access ---
		
		reference	Vector<T>::at(size_type pos)
		{
			if (pos > _current)
			{
				throw std::out_of_range("Position out of range");
			}
			else
			{
				return _v[pos];
			}
		}
		
	// 	reference	Vector<T>::operator[](const size_type pos)
	// 	{
	// 		return _v[pos];
	// 	}
		
	// 	reference	Vector<T>::front(void)
	// 	{
	// 		return _v[0];
	// 	}
		
	// 	reference	Vector<T>::back
	// 	{
	// 		return _v[_current];
	// 	}
		
	// 	reference	Vector<T>::data;

	// 	// --- Iterators ---

	// 	Vector<T>::begin;
	// 	Vector<T>::end;
	// 	Vector<T>::rbegin;
	// 	Vector<T>::rend;

	// 	// --- Capacity ---

	// 	Vector<T>::empty;
	// 	Vector<T>::size;
	// 	Vector<T>::max_size;
	// 	Vector<T>::reserve;
	// 	Vector<T>::capacity;

	// 	// --- Modifiers ---

	// 	Vector<T>::clear;
	// 	Vector<T>::insert;
	// 	Vector<T>::erase;
	// 	Vector<T>::push_back;
	// 	Vector<T>::pop_back;
	// 	Vector<T>::resize;
	// 	Vector<T>::swap;

		// --------------- NON-MEMBER FUNCTIONS ---------------
		
		bool	Vector<T>::operator==(const Fixed & rhs) const
		{
			return (std::equal(*this->begin(), *this->end(), rhs.begin()));
		}
		
		bool	Vector<T>::operator!=(const Fixed & rhs) const
		{
			return (!std::equal(*this->begin(), *this->end(), rhs.begin()));
		}
		
		bool	Vector<T>::operator<(const Fixed & rhs) const
		{
			return (std::less(*this->begin(), *this->end(), rhs.begin()));
		}
		
		bool	Vector<T>::operator<=(const Fixed & rhs) const;
		bool	Vector<T>::operator>(const Fixed & rhs) const;
		bool	Vector<T>::operator>=(const Fixed & rhs) const;
		
	// 	// void	swap();


	private:

		pointer			_v;			// start of allocation
		size_type		_current;	// end of elements, start of space allocated for possible expansion
		size_type		_capacity;	// end of allocated space
		allocator_type	_alloc;		// allocator
	
};

#endif
