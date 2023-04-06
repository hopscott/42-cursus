/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:01:09 by swillis           #+#    #+#             */
/*   Updated: 2023/01/10 18:16:15 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_H
# define RANDOMACCESSITERATOR_H

namespace ft
{
	template< typename T >
	class RandomAccessIterator{
		
		public:
		
			// --------------- MEMBER TYPES ---------------

			typedef T                               	value_type;
			typedef T*                              	pointer;
			typedef T&                              	reference;
			typedef std::ptrdiff_t                  	difference_type;
			typedef std::random_access_iterator_tag 	iterator_category;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// Default Constructor
			RandomAccessIterator<T>( void )
			{
				return;
			}
			
			// Parametric Constructor
			RandomAccessIterator<T>( pointer ptr )
			: _ptr(ptr)
			{
				return;
			}

			// Copy Constructor
			RandomAccessIterator<T>( RandomAccessIterator<T> const & src )
			: _ptr(src._ptr)
			{
				return;
			}
			
			// Destructor
			~RandomAccessIterator<T>( void )
			{
				return;
			}

			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			RandomAccessIterator<T> &	operator=(const RandomAccessIterator<T> & rhs)
			{
				if (this != &rhs)
				{
					_ptr = rhs._ptr;
				}

				return (*this);
			}
			
			// --------------- MEMBER FUNCTIONS ---------------
		
			// Dereference operator
			reference	operator*(void) const 
			{ 
				return *_ptr; 
			}
			
			pointer		operator->(void) const 
			{ 
				return _ptr; 
			}

			// Increment and decrement operators
			RandomAccessIterator<T>&	operator++()
			{ 
				++_ptr;
				return *this;
			}
			
			RandomAccessIterator<T>	operator++(int)
			{ 
				RandomAccessIterator<T>	tmp(*this); 

				++_ptr; 
				return tmp; 
			}

			RandomAccessIterator<T>& operator--()
			{ 
				--_ptr; 
				return *this; 
			}
			
			RandomAccessIterator<T>	operator--(int)
			{ 
				RandomAccessIterator<T>	tmp(*this); 
	
				--_ptr; 
				return tmp; 
			}

			// Comparison operators
			bool operator==(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr == rhs._ptr; 
			}
			
			bool operator!=(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr != rhs._ptr;
			}
			
			bool operator<(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr < rhs._ptr; 
			}
			
			bool operator>(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr > rhs._ptr; 
			}
			
			bool operator<=(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr <= rhs._ptr; 
			}
			
			bool operator>=(const RandomAccessIterator<T>& rhs) const 
			{ 
				return _ptr >= rhs._ptr; 
			}

			// Addition and subtraction operators
			RandomAccessIterator<T>	operator+(difference_type n) const 
			{ 
				return RandomAccessIterator<T>(_ptr + n); 
			}
			
			RandomAccessIterator<T>	operator-(difference_type n) const 
			{ 
				return RandomAccessIterator<T>(_ptr - n); 
			}
			
			difference_type			operator-(const RandomAccessIterator& rhs) const 
			{ 
				return _ptr - rhs._ptr; 
			}

			// Compound assignment operators
			RandomAccessIterator<T>&	operator+=(difference_type n) 
			{ 
				_ptr += n; 
				return *this; 
			}
			
			RandomAccessIterator<T>&	operator-=(difference_type n) 
			{ 
				_ptr -= n; 
				return *this; 
			}

			// Array access operator
			reference		operator[](difference_type n) const
			{ 
				return _ptr + n; 
			}

		private:
		
			pointer _ptr;
		
	};
}

#endif
