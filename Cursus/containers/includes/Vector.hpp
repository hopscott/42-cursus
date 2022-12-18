/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 01:01:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <cmath>

# include "iterTraits.hpp"
# include "RandomAccessIterator.hpp"
# include "ReverseIterator.hpp"

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

			typedef ft::iterator_traits< RandomAccessIterator<T> >		iterator;
			typedef const iterator									const_iterator;
			
			typedef ft::reverse_iterator< iterator >				reverse_iterator;
			typedef const ft::reverse_iterator< const_iterator >	const_reverse_iterator;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// https://stackoverflow.com/questions/2509499/how-to-use-stdallocator-in-my-own-container-class
		
			// Default Constructor
			Vector<T>( void )
			: _v(nullptr), _capacity(0), _current(0)
			{
				return;
			}

			// Parametric Constructor
			Vector<T>( const unsigned int n )
			: _v(nullptr), _capacity(n), _current(0)
			{
				_v = _allocator.allocate(_capacity, 0);
				
				return;
			}

			// Copy Constructor
			Vector<T>( Vector<T> const & src )
			: _v(nullptr), _capacity(src._capacity), _current(src._current)
			{
				_v = alloc.allocate(_capacity, 0);
				assign(src.begin(), src.end());

				return;
			}
		
			// Destructor
			~Vector<T>( void )
			{
				for (size_type idx=0; idx<_current; ++idx)
				{
					_allocator.destroy(_v[idx]);
				}
				_allocator.deallocate(_v, _capacity);
				
				return;
			}
		
			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			Vector<T> &	operator=(const Vector<T> & rhs)
			{
				if (this != &rhs)
				{
					for (size_type idx=0; idx<_current; ++idx)
					{
						_allocator.destroy(_v[idx]);
					}
					_allocator.deallocate(_v, _capacity);

					_capacity = rhs._capacity;
					_v = _allocator.allocate(_capacity, 0);
					assign(rhs.begin(), rhs.end());
				}

				return (*this);
			}

			// --------------- MEMBER FUNCTIONS ---------------
			
			// === ASSIGN ===

			void	assign( size_type count, const_reference value )
			{
				for (size_type idx=0; idx<count; ++idx)
				{
					(*this)[idx] = value;
				}
				_current = count;
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
				_current = idx;
			}

			// === GET_ALLOCATOR ===
			
			allocator_type	get_allocator() const
			{
				return _allocator;
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
				if (_v == nullptr || idx >= _capacity)
				{
					throw std::out_of_range("Index out of range");
				}

				return _v[idx];
			}
			
			const_reference	operator[](size_type idx) const
			{
				if (_v == nullptr || idx >= _capacity)
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
				return (*this)[_current - 1];
			}
			
			const_reference	back(void) const
			{
				return (*this)[_current - 1];
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
		
			// === END ===
			
			iterator	end(void)
			{
				iterator	ite(_v[_current - 1]);

				return ite;
			}
			
			// === RBEGIN ===
			
			iterator	rbegin(void)
			{
				reverse_iterator	rite(_v);
				
				return rite;
			}
			
			// === REND ===
			
			iterator	rend(void)
			{
				reverse_iterator	rite(_v[_current - 1]);
				
				return rite;
			}

			// --- Capacity ---

			// === EMPTY ===

			bool	empty(void) const
			{
				return (begin() == end());	
			}
			
			// === SIZE ===

			size_type	size(void) const
			{
				return (std::distance(begin(), end()));
			}
			
			// === MAX SIZE ===
			
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(T));
			}
			
			// === RESERVE ===
			
			void	reserve( size_type new_cap )
			{
				if (new_cap > max_size())
				{
					throw std::length_error();
				}
				
				pointer			new_v;
	
				new_v = _allocator.allocate(new_cap, 0);
				if (!new_v)
				{
					throw std::bad_alloc();
				}
				
				for (size_type idx=0; idx<_current; ++idx)
				{
					_alloctor.construct(new_v[idx], _v[idx]);
					_allocator.destroy(_v[idx]);
				}
				_allocator.deallocate(_v, _capacity);
				
				_v = new_v;
				_capacity = new_cap;
			}
			
			// === CAPACITY ===
			
			size_type capacity(void) const
			{
				return _capacity;
			}

			// --- Modifiers ---

			// === CLEAR ===
			
			void	clear(void)
			{
				for (size_type idx=0; idx<_current; ++idx)
				{
					_allocator.destroy(_v[idx]);
				}
				_current = 0;
			}
			
			// === INSERT ===
			
			iterator Vector<T>::insert( const_iterator pos, const T& value )
			{
				
			}

			iterator Vector<T>::insert( const_iterator pos, size_type count, const T& value )
			{
				
			}

			template< class InputIt >
			iterator Vector<T>::insert( const_iterator pos, InputIt first, InputIt last )
			{
				
				
			}

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
			A				_allocator;
		
	};
};

#endif
