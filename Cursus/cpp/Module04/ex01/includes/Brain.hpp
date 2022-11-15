/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 21:55:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <ctime>
# include <cstdlib>
# include <unistd.h>

class Brain {

	private:

		std::string		_ideas[100];
		void			deepCopy( const Brain& src );

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Brain( void );

		// Copy Constructor
		Brain( Brain const & src );
	
		// Destructor
		virtual ~Brain( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Brain &	operator=(const Brain & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string			ideaGenerator( void ) const;
		void				firstFiveIdeas( void ) const;
};

#endif
