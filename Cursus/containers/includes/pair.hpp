/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:01:09 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 23:50:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

namespace ft
{
	template<class T1, class T2>
	class pair
	{
		
		public:
		
			// --------------- MEMBER TYPES ---------------

			// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
		
			// Default Constructor
			pair<T1,T2>( void )
			: first(0), second(0)
			{
				return;
			}
			
			// Parametric Constructor
			pair<T1,T2>( const T1 & fst, const T2 & scd )
			: first(fst), second(scd)
			{
				return;
			}

			// Copy Constructor
			pair<T1,T2>( pair<T1,T2> const & src )
			: first(src.first), second(src.second)
			{
				return;
			}
			
			// Destructor
			~pair<T1,T2>( void )
			{
				return;
			}

			// --------------- OPERATOR OVERLOADS ---------------
		
			// Copy Assignment Operator Overload
			pair<T1,T2> &	operator=(const pair<T1,T2> & rhs)
			{
				if (this != &rhs)
				{
					first = rhs.first;
					second = rhs.second;
				}

				return (*this);
			}
			
			// --------------- MEMBER FUNCTIONS ---------------
		
			// --------------- MEMBER OBJECTS ---------------
		
			T1	first;
			T2	second;

		private:
		
	};
}

#endif
