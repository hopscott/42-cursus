/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 18:49:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor - initializes the Point-point number value to 0
Point::Point(void) : _x(0), _y(0) {

	return;
}

// Parameterised Constructors
Point::Point(float const x, float const y) : _x(x), _y(y) {

	return;
}

// Copy Constructor
Point::Point(Point const & src) {

	*this = src;

	return;
}

// Destructor
Point::~Point(void) {

    return;
}


// --------------- OPERATOR OVERLOADS ---------------

// https://stackoverflow.com/questions/11601998/assignment-of-class-with-const-member

// Copy Assignment Operator Overload
Point &	Point::operator=(const Point & rhs) {

	this->~Point();
	return *new(this) Point(rhs.getX().toFloat(), rhs.getY().toFloat()); 
}


// --------------- FUNCTIONS ---------------

// Member functions
const Fixed &		Point::getX( void ) const {
	
	return _x;
}

const Fixed &		Point::getY( void ) const {
	
	return _y;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Point const & rhs ) {

	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return o;
}
