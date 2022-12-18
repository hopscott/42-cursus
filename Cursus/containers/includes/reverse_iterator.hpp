/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:01:09 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 22:47:12 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "utils.hpp"

namespace ft
{
	template< typename Iterator >
	class reverse_iterator
	{
		
		public:
		
			// --------------- MEMBER TYPES ---------------

			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// Default Constructor
			reverse_iterator<Iterator>( void )
			{
				return;
			}
			
			// Parametric Constructor
			reverse_iterator<Iterator>( Iterator ite )
			: _ite(ite)
			{
				return;
			}

			// Copy Constructor
			reverse_iterator<Iterator>( reverse_iterator<Iterator> const & src )
			: _ite(src._ite)
			{
				return;
			}
			
			// Destructor
			~reverse_iterator<Iterator>( void )
			{
				return;
			}

			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			reverse_iterator<Iterator> &	operator=(const reverse_iterator<Iterator> & rhs)
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
			reverse_iterator<Iterator>&	operator++()
			{ 
				--_ite;
				return *this;
			}
			
			reverse_iterator<Iterator>	operator++(int)
			{ 
				reverse_iterator<Iterator>	tmp(*this); 

				--_ite; 
				return tmp; 
			}

			reverse_iterator<Iterator>& operator--()
			{ 
				++_ite; 
				return *this; 
			}
			
			reverse_iterator<Iterator>	operator--(int)
			{ 
				reverse_iterator<Iterator>	tmp(*this); 
	
				++_ite; 
				return tmp; 
			}

			// Comparison operators
			bool operator==(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite == rhs._ite; 
			}
			
			bool operator!=(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite != rhs._ite;
			}
			
			bool operator<(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite > rhs._ite; 
			}
			
			bool operator>(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite < rhs._ite; 
			}
			
			bool operator<=(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite >= rhs._ite; 
			}
			
			bool operator>=(const reverse_iterator<Iterator>& rhs) const 
			{ 
				return _ite <= rhs._ite; 
			}

			// Addition and subtraction operators
			reverse_iterator<Iterator>	operator+(difference_type n) const 
			{ 
				return reverse_iterator(_ite - n); 
			}
			
			reverse_iterator<Iterator>	operator-(difference_type n) const 
			{ 
				return reverse_iterator(_ite + n); 
			}
			
			difference_type			operator-(const Iterator& rhs) const 
			{ 
				return _ite - rhs._ite; 
			}

			// Compound assignment operators
			reverse_iterator<Iterator>&	operator+=(difference_type n) 
			{ 
				_ite -= n; 
				return *this; 
			}
			
			reverse_iterator<Iterator>&	operator-=(difference_type n) 
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
