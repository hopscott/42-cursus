/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/11 18:23:57 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <cmath>
# include "iter.hpp"

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define RESET		"\x1b[0m"

// https://www.stroustrup.com/except.pdf
// https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c


namespace ft
{
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
			

			// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
			// https://en.cppreference.com/w/cpp/iterator/iterator
			
			typedef std::iterator< 
									typename ft::iterator_traits<value_type>::iterator_category,
									typename ft::iterator_traits<value_type>::value_type,
									typename ft::iterator_traits<value_type>::difference_type,
									typename ft::iterator_traits<value_type>::pointer,
									typename ft::iterator_traits<value_type>::reference
									>		iterator;
			
			typedef const std::iterator< 
									typename ft::iterator_traits<value_type>::iterator_category,
									typename ft::iterator_traits<value_type>::value_type,
									typename ft::iterator_traits<value_type>::difference_type,
									typename ft::iterator_traits<value_type>::pointer,
									typename ft::iterator_traits<value_type>::reference
									>		const_iterator;
			
			// typedef ft::reverse_iterator<iterator>						reverse_iterator;
			// typedef const ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// https://stackoverflow.com/questions/2509499/how-to-use-stdallocator-in-my-own-container-class
		
			// Default Constructor
			Vector<T>( void )
			: _v(NULL), _capacity(1), _current(0)
			{
				//Allocator
				allocator_type	alloc;

				_v = alloc.allocate(_capacity, 0);
				
				return;
			}

			// Parametric Constructor
			Vector<T>( const unsigned int n )
			: _v(NULL), _capacity(n), _current(0)
			{
				//Allocator
				allocator_type	alloc;

				_v = alloc.allocate(_capacity, 0);
				
				return;
			}

			// Copy Constructor
			Vector<T>( Vector<T> const & src )
			: _v(NULL), _capacity(src._capacity), _current(src._current)
			{
				//Allocator
				allocator_type	alloc;

				_v = alloc.allocate(_capacity, 0);
				
				//Copy array
				assign(src.begin(), src.end());

				return;
			}
		
			// Destructor
			~Vector<T>( void )
			{
				//Allocator
				allocator_type	alloc;

				alloc.deallocate(_v, _capacity);
				
				return;
			}
		
			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			Vector<T> &	operator=(const Vector<T> & rhs)
			{
				if (this != &rhs)
				{
					//Allocator
					allocator_type	alloc;

					alloc.deallocate(_v, _capacity);
					_v = NULL;

					//Copy array
					_capacity = rhs._capacity;
					_current = rhs._current;
					assign(rhs.begin(), rhs.end());
				}

				return (*this);
			}

			// --------------- MEMBER FUNCTIONS ---------------
			
			// === ASSIGN ===

			void	assign( size_type count, const_reference value )
			{
				size_type	idx;

				for (size_type idx=0; idx<count; ++idx)
				{
					(*this)[idx] = value;
				}
			}
		
			template< class InputIt >
			void	assign( InputIt first, InputIt last )
			{
				size_type	idx;

				idx = 0;
				for (InputIt ite=first; ite<last; ++ite)
				{
					(*this)[idx++] = *ite;
				}
			}

			// === GET_ALLOCATOR ===
			
			allocator_type	get_allocator() const
			{
				allocator_type	alloc;

				return alloc;
			}
			
			// --- Element access ---

			// === AT ===

			reference	at(size_type idx)
			{
				return (*this)[idx];
			}
			
			const_reference at( size_type idx ) const
			{
				return (*this)[idx];
			}

			// === [] ===

			reference	operator[](size_type idx)
			{
				if (_v == NULL || idx >= _capacity)
				{
					throw std::out_of_range("Index out of range");
				}

				return _v[idx];
			}
			
			const_reference	operator[](size_type idx) const
			{
				if (_v == NULL || idx >= _capacity)
				{
					throw std::out_of_range("Index out of range");
				}

				return _v[idx];
			}

			// === FRONT ===

			reference	front(void)
			{
				return (*this)[0];
			}

			const_reference	front(void) const
			{
				return (*this)[0];
			}
			
			// === BACK ===
			
			reference	back(void)
			{
				return (*this)[_current];
			}
			
			const_reference	back(void) const
			{
				return (*this)[_current];
			}
	
			// === DATA ===
			
			value_type*	data(void)
			{
				return _v;
			}

			const value_type*	data(void) const
			{
				return _v;
			}

			// --- Iterators ---

			// === BEGIN ===
			
			iterator	begin(void)
			{
				iterator	ite(_v);

				return ite; 
			}
		
			iterator	end(void)
			{
				iterator	ite(_v[_current]);

				return ite;
			}
			// iterator	Vector<T>::rbegin;
			// iterator	Vector<T>::rend;

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
			
			// bool	Vector<T>::operator==(const Fixed & rhs) const
			// {
			// 	return (std::equal(*this->begin(), *this->end(), rhs.begin()));
			// }
			
			// bool	Vector<T>::operator!=(const Fixed & rhs) const
			// {
			// 	return (!std::equal(*this->begin(), *this->end(), rhs.begin()));
			// }
			
			// bool	Vector<T>::operator<(const Fixed & rhs) const
			// {
			// 	return (std::less(*this->begin(), *this->end(), rhs.begin()));
			// }
			
			// bool	Vector<T>::operator<=(const Fixed & rhs) const;
			// bool	Vector<T>::operator>(const Fixed & rhs) const;
			// bool	Vector<T>::operator>=(const Fixed & rhs) const;
			
		// 	// void	swap();


		private:

			pointer			_v;
			size_type		_capacity;
			size_type		_current;
		
	};
};

#endif
