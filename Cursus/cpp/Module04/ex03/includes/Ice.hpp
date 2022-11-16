/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Ice( void );

		// Copy Constructor
		Ice( Ice const & src );
	
		// Destructor
		~Ice( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Ice &	operator=(const Ice & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string const &		getType(void) const; 			// Returns the materia type
		Ice*					clone(void) const;
		void					use(ICharacter& target);

		// Static functions

};

#endif
