/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 02:32:52 by swillis          ###   ########.fr       */
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
		~Animal( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Animal &	operator=(const Animal & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string &	getType( void ) const;
		void			makeSound( void ) const;

		// Static functions

};

#endif
