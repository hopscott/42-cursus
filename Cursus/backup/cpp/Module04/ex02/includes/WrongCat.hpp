/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:44:12 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		WrongCat( void );

		// Copy Constructor
		WrongCat( WrongCat const & src );
	
		// Destructor
		virtual ~WrongCat( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		WrongCat &	operator=(const WrongCat & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &		getType( void ) const;
		void					makeSound( void ) const;

		// Static functions

};

#endif
