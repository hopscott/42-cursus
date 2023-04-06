/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:15:10 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal {

	private:

		Brain*	_brain;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Dog( void );

		// Copy Constructor
		Dog( Dog const & src );
	
		// Destructor
		~Dog( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Dog &	operator=(const Dog & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &		getType( void ) const;
		void					makeSound( void ) const;
		const Brain*			getBrain( void ) const;

		// Static functions

};

#endif
