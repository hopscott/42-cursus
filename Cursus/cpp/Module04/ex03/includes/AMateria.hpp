/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "ICharacter.hpp"

class AMateria {

	protected:

		std::string		_type;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		AMateria(std::string const & type);

		// Copy Constructor
		AMateria( AMateria const & src );
	
		// Destructor
		virtual ~AMateria( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		AMateria &	operator=(const AMateria & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string const &		getType(void) const; 		// Returns the materia type
		virtual AMateria*		clone(void) const = 0;		// Pure virtual function
		virtual void			use(ICharacter& target);	// Prints

		// Static functions

};

#endif
