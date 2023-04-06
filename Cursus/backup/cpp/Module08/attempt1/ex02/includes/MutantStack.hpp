/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/12/05 18:09:24 by swillis          ###   ########.fr       */
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
# include <stack>

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
		MutantStack( void )
		{
			return;
		};

		// Parametric Constructor

		// Copy Constructor
		MutantStack( MutantStack const & src )
		{
			for (size_t i=0; i<src.size(); ++i)
			{
				this->push(src[i]);
			}
			return;
		};

		// Destructor
		~MutantStack( void )
		{
			for (size_t i=0; i<this->size(); ++i)
			{
				this->pop();
			}
			
			return;
		};

		// --------------- OPERATOR OVERLOADS ---------------

		// Copy Assignment Operator Overload
		MutantStack &	operator=(const MutantStack & rhs)
		{
			if (this != &rhs)
			{
				for (size_t i=0; i<rhs.size(); ++i)
				{
					this->push(rhs[i]);
				}
			}

			return (*this);
		};
		
		// --------------- FUNCTIONS ---------------
		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void)
		{
			return this->c.begin();
		};

		iterator	end(void)
		{
			return this->c.end();
		};
	
		// Member functions

	private:

};

#endif
