/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 21:37:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>
# include <algorithm>

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define RESET		"\x1b[0m"

class Span {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Span( void );

		// Parametric Constructor
		Span( const unsigned int N );

		// Copy Constructor
		Span( Span const & src );
	
		// Destructor
		~Span( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Span &	operator=(const Span & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void		addNumber(int n);
		int			shortestSpan(void);
		int			longestSpan(void);

		template <typename C>
		void		addIterNumbers(typename C::const_iterator it);

	private:

		unsigned int		_maxsize;
		unsigned int		_idx;
		int*				_arr;

};

#endif
