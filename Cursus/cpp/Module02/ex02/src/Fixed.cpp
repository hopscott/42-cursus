/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 18:57:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor - initializes the fixed-point number value to 0
Fixed::Fixed(void) {

	std::cout << "Default constructor called" << std::endl;
    _nval = 0;

	return;
}

// Parameterised Constructors
Fixed::Fixed(int const i) {

	int	x;

	std::cout << "Int constructor called" << std::endl;

	x = roundf(i * (1 << _nfract_bits));
	setRawBits(x);

	return;
}

Fixed::Fixed(float const f) {

	int	x;

	std::cout << "Float constructor called" << std::endl;

	x = roundf(f * (1 << _nfract_bits));
	setRawBits(x);

	return;
}

// Copy Constructor
Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

// Destructor
Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

    return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Fixed &	Fixed::operator=(const Fixed & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return *this;

    setRawBits(rhs.getRawBits());

    return *this;
}

// Comparison Operator Overloads
Fixed &	Fixed::operator>(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator<(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator>=(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator<=(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator==(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator!=(const Fixed & rhs) {
	
}


// Arithmetic Operator Overloads
Fixed &	Fixed::operator+(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator-(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator*(const Fixed & rhs) {
	
}

Fixed &	Fixed::operator/(const Fixed & rhs) {
	
}


// Increment/Decrement Operator Overloads
Fixed &	Fixed::operator++( void ) {
	
}

Fixed &	Fixed::operator++( int n ) {
	
}

Fixed &	Fixed::operator--( void ) {
	
}

Fixed &	Fixed::operator--( int n ) {
	
}


// --------------- FUNCTIONS ---------------

// Member functions
int		Fixed::getRawBits( void ) const {

	return _nval;
}

void	Fixed::setRawBits( int const raw ) {

	_nval = raw;
}

float	Fixed::toFloat( void ) const {

	return (float)_nval / (float)(1 << _nfract_bits);
}

int		Fixed::toInt( void ) const {

	return _nval >> _nfract_bits;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
