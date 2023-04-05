/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Cure( void );

		// Copy Constructor
		Cure( Cure const & src );
	
		// Destructor
		~Cure( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Cure &	operator=(const Cure & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string const &		getType(void) const; 			// Returns the materia type
		Cure*					clone(void) const;
		void					use(ICharacter& target);

		// Static functions

};

#endif
