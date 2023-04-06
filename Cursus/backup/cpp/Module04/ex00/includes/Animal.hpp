/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:34:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class Animal {

	protected:

		std::string		_type;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Animal( void );

		// Copy Constructor
		Animal( Animal const & src );
	
		// Destructor
		virtual ~Animal( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Animal &	operator=(const Animal & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &	getType( void ) const;
		virtual void				makeSound( void ) const;

		// Static functions

};

#endif
