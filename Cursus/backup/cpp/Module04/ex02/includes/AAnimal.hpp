/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:12:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class AAnimal {

	protected:

		std::string		_type;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		AAnimal( void );

		// Copy Constructor
		AAnimal( AAnimal const & src );
	
		// Destructor
		virtual ~AAnimal( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		AAnimal &	operator=(const AAnimal & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &		getType( void ) const;
		virtual void			makeSound( void ) const = 0; // Pure virtual function

		// Static functions

};

#endif
