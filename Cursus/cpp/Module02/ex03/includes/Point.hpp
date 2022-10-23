/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/23 19:28:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {

	private:

		const Fixed	_x;
		const Fixed	_y;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Point( void );

		// Parameterised Constructors
		Point( float const x, float const y );

		// Copy Constructor
		Point( Point const & src );
	
		// Destructor
		~Point( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Point &	operator=(const Point & rhs);

		// // Comparison Operator Overloads
		// bool	operator==(const Point & rhs) const;
		// bool	operator!=(const Point & rhs) const;

		// // Arithmetic Operator Overloads
		// Point &	operator+(const Point & rhs);
		// Point &	operator-(const Point & rhs);
		// Point &	operator*(const Point & rhs);
		// Point &	operator/(const Point & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const Fixed	&	getX( void ) const;
		const Fixed	&	getY( void ) const;
	
		void			setX( const Fixed & f );
		void			setY( const Fixed & f );
};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Point const & rhs );

#endif
