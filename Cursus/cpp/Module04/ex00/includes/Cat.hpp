/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 02:33:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include "Animal.hpp"

class Cat: public Animal {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Cat( void );

		// Copy Constructor
		Cat( Cat const & src );
	
		// Destructor
		~Cat( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Cat &	operator=(const Cat & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		std::string &	getType( void ) const;
		void			makeSound( void ) const;

		// Static functions

};

#endif
