/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 18:04:18 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>

class Data {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Data( void );

		// Parametric Constructor
		Data( const int a, const int b, const int c );

		// Copy Constructor
		Data( Data const & src );
	
		// Destructor
		~Data( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Data &	operator=(const Data & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		int		getA(void) const;
		int		getB(void) const;
		int		getC(void) const;
		
	private:

		int	_a;
		int	_b;
		int	_c;

};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Data const & rhs );

#endif
