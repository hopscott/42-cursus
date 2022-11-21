/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/21 01:56:31 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class Converter {

	private:


	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Converter( void );

		// Copy Constructor
		Converter( Converter const & src );
	
		// Destructor
		~Converter( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Converter &	operator=(const Converter & rhs);

		// Conversions
		operator float(void);
		operator int(void);

		// --------------- FUNCTIONS ---------------
	
		// Member functions

};

#endif
