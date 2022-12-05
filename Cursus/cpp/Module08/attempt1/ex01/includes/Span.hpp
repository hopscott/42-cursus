/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/05 18:48:34 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>
# include <algorithm>
# include <vector>

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
		size_t		shortestSpan(void);
		size_t		longestSpan(void);

		template <typename T>
		void		addIterNumbers(typename std::vector<T>::const_iterator begin, typename std::vector<T>::const_iterator end)
		{
			for (typename std::vector<T>::iterator it=begin; it!=end; ++it)
			{
				addNumber(*it);
			}
		};


	private:

		unsigned int		_maxsize;
		unsigned int		_idx;
		int*				_arr;

};

#endif
