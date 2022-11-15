/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:44:18 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class WrongAnimal {

	protected:

		std::string		_type;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		WrongAnimal( void );

		// Copy Constructor
		WrongAnimal( WrongAnimal const & src );
	
		// Destructor
		virtual ~WrongAnimal( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		WrongAnimal &	operator=(const WrongAnimal & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &		getType( void ) const;
		void					makeSound( void ) const;

		// Static functions

};

#endif
