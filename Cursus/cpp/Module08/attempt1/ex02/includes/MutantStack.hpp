/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/03 21:27:05 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>
# include <algorithm>
# include <vector>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"

template< typename T >
class MutantStack: public std::stack<T> {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

		// Default Constructor
		MutantStack( void );

		// Parametric Constructor

		// Copy Constructor
		MutantStack( MutantStack const & src );

		// Destructor
		~MutantStack( void );

		// --------------- OPERATOR OVERLOADS ---------------

		// Copy Assignment Operator Overload
		MutantStack &	operator=(const MutantStack & rhs);

		// --------------- FUNCTIONS ---------------
		std::stack<T>::container_type::iterator    begin(void)
		{
			return c.begin();
		}
		std::stack<T>::container_type::iterator    end(void)
		{
			return c.end();
		}
	
		// Member functions

	private:

};

#endif
