/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/23 19:29:06 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor - initializes the Point-point number value to 0
Point::Point(void) : _x(0), _y(0) {

	return;
}

// Parameterised Constructors
Point::Point(float const x, float const y) : _x(x), _y(y)  {

	return;
}

// Copy Constructor
Point::Point(Point const & src) {

	setX(src.getX());
	setY(src.getY());

	return;
}

// Destructor
Point::~Point(void) {

    return;
}


// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Point &	Point::operator=(const Point & rhs) {

    if (this == &rhs)
        return *this;

	setX(rhs.getX());
	setY(rhs.getY());

    return *this;
}

// // Comparison Operator Overloads
// bool	Point::operator==(const Point & rhs) const {

// 	return ((getX() == rhs.getX()) && (getY() == rhs.getY()));
// }

// bool	Point::operator!=(const Point & rhs) const {

// 	return ((getX() != rhs.getX()) || (getY() != rhs.getY()));
// }


// // Arithmetic Operator Overloads
// // Addition 
// Point &	Point::operator+(const Point & rhs) {
	
// 	Point *result = new Point;

// 	result->setRawBits((int)tmp);
// 	return *result;
// }

// // Subtraction
// Point &	Point::operator-(const Point & rhs) {
	
// 	Point *result = new Point;

// 	result->setRawBits((int)tmp);
// 	return *result;
// }

// // Multiplication
// Point &	Point::operator*(const Point & rhs) {

// 	Point *result = new Point;

// 	result->setRawBits((int)tmp);
// 	return *result;
// }

// // Division
// Point &	Point::operator/(const Point & rhs) {

// 	Point *result = new Point;

// 	result->setRawBits((int)tmp);
// 	return *result;
// }


// --------------- FUNCTIONS ---------------

// Member functions
const Fixed	&	Point::getX( void ) const {
	
	return _x;
}

const Fixed	&	Point::getY( void ) const {
	
	return _y;
}

void			Point::setX( Fixed const & f ) {

	_x = f;
}

void			Point::setY( Fixed const & f ) {
	
	_y = f;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Point const & rhs ) {

	o << "x: " << rhs.getX() << " y: " << rhs.getY();
	return o;
}
