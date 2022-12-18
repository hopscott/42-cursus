/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:01:09 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 00:34:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_H
# define REVERSEITERATOR_H

# include "iterTraits.hpp"

namespace ft
{
	template< typename Iterator >
	class ReverseIterator:
	{
		
		public:
		
			// --------------- MEMBER TYPES ---------------

			typedef ft::iterator_traits<Iterator>::value_type			value_type;
			typedef ft::iterator_traits<Iterator>::pointer				pointer;
			typedef ft::iterator_traits<Iterator>::reference			reference;
			typedef ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// Default Constructor
			ReverseIterator<Iterator>( void )
			{
				return;
			}
			
			// Parametric Constructor
			ReverseIterator<Iterator>( Iterator ite )
			: _ite(ite)
			{
				return;
			}

			// Copy Constructor
			ReverseIterator<Iterator>( ReverseIterator<Iterator> const & src )
			: _ite(src._ite)
			{
				return;
			}
			
			// Destructor
			~ReverseIterator<Iterator>( void )
			{
				return;
			}

			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			ReverseIterator<Iterator> &	operator=(const ReverseIterator<Iterator> & rhs)
			{
				if (this != &rhs)
				{
					_ite = rhs._ite;
				}

				return (*this);
			}
			
			// --------------- MEMBER FUNCTIONS ---------------
		
			// Dereference operator
			reference	operator*(void) const 
			{ 
				return *(_ite - 1); 
			}
			
			pointer		operator->(void) const 
			{ 
				return &(*(_ite - 1)); 
			}

			// Increment and decrement operators
			ReverseIterator<Iterator>&	operator++()
			{ 
				--_ite;
				return *this;
			}
			
			ReverseIterator<Iterator>	operator++(int)
			{ 
				ReverseIterator<Iterator>	tmp(*this); 

				--_ite; 
				return tmp; 
			}

			ReverseIterator<Iterator>& operator--()
			{ 
				++_ite; 
				return *this; 
			}
			
			ReverseIterator<Iterator>	operator--(int)
			{ 
				ReverseIterator<Iterator>	tmp(*this); 
	
				++_ite; 
				return tmp; 
			}

			// Comparison operators
			bool operator==(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite == rhs._ite; 
			}
			
			bool operator!=(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite != rhs._ite;
			}
			
			bool operator<(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite > rhs._ite; 
			}
			
			bool operator>(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite < rhs._ite; 
			}
			
			bool operator<=(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite >= rhs._ite; 
			}
			
			bool operator>=(const ReverseIterator<Iterator>& rhs) const 
			{ 
				return _ite <= rhs._ite; 
			}

			// Addition and subtraction operators
			ReverseIterator<Iterator>	operator+(difference_type n) const 
			{ 
				return ReverseIterator(_ite - n); 
			}
			
			ReverseIterator<Iterator>	operator-(difference_type n) const 
			{ 
				return ReverseIterator(_ite + n); 
			}
			
			difference_type			operator-(const iterator& rhs) const 
			{ 
				return _ite - rhs._ite; 
			}

			// Compound assignment operators
			ReverseIterator<Iterator>&	operator+=(difference_type n) 
			{ 
				_ite -= n; 
				return *this; 
			}
			
			ReverseIterator<Iterator>&	operator-=(difference_type n) 
			{ 
				_ite += n; 
				return *this; 
			}

			// Array access operator
			reference		operator[](difference_type n) const
			{ 
				return *(_ite - n - 1); 
			}

		private:
		
			Iterator _ite;
		
	};
}

#endif
