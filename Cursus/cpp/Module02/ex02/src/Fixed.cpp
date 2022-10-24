/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 17:59:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor - initializes the fixed-point number value to 0
Fixed::Fixed(void) {

    _nval = 0;

	return;
}

// Parameterised Constructors
Fixed::Fixed(int const i) {

	_nval = i * (1 << _nfract_bits);

	return;
}

Fixed::Fixed(float const f) {

	_nval = roundf(f * (1 << _nfract_bits));

	return;
}

// Copy Constructor
Fixed::Fixed(Fixed const & src) {

	*this = src;

	return;
}

// Destructor
Fixed::~Fixed(void) {

    return;
}


// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Fixed &	Fixed::operator=(const Fixed & rhs) {

    if (this != &rhs) {
		
		_nval = rhs._nval;
	}

    return *this;
}

// Comparison Operator Overloads
bool	Fixed::operator>(const Fixed & rhs) const {
	
	return (_nval > rhs._nval);
}

bool	Fixed::operator<(const Fixed & rhs) const {
	
	return (_nval < rhs._nval);
}

bool	Fixed::operator>=(const Fixed & rhs) const {
	
	return (_nval >= rhs._nval);
}

bool	Fixed::operator<=(const Fixed & rhs) const {

	return (_nval <= rhs._nval);
}

bool	Fixed::operator==(const Fixed & rhs) const {

	return (_nval == rhs._nval);
}

bool	Fixed::operator!=(const Fixed & rhs) const {

	return (_nval != rhs._nval);
}


// Arithmetic Operator Overloads

// https://en.wikipedia.org/wiki/Q_%28number_format%29#Math_operations

// Q(m.n) -> w = 32 bits total for int -> 1 bit for sign
// n = number of bits for fraction bits -> n = 8
// m = number of bits for integer value -> m = 31 - 8 = 23

// Addition with saturation
Fixed	Fixed::operator+(const Fixed & rhs) const {
	
	signed long	tmp;
	Fixed		result;

	tmp = _nval + rhs._nval;

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	result._nval = (int)tmp;
	return result;
}

// Subtraction with saturation
Fixed	Fixed::operator-(const Fixed & rhs) const {

	signed long	tmp;
	Fixed		result;

	tmp = _nval - rhs._nval;

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	result._nval = (int)tmp;
	return result;
}

// Multiplication with saturation
Fixed	Fixed::operator*(const Fixed & rhs) const {

	signed long	tmp;
	Fixed		result;

	tmp = _nval * rhs._nval;
	tmp += (1 << (_nfract_bits - 1));
	tmp = (tmp >> _nfract_bits);

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	result._nval = (int)tmp;
	return result;
}

// Division with saturation
Fixed	Fixed::operator/(const Fixed & rhs) const {

	signed long	tmp;
	Fixed		result;

	tmp = _nval << _nfract_bits;
	
	if ((tmp >= 0 && rhs._nval >= 0) || (tmp < 0 && rhs._nval < 0))
		tmp += (rhs._nval >> 1);
	else
		tmp -= (rhs._nval >> 1);

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	result._nval = (int)tmp;
	return result;
}


// Increment/Decrement Operator Overloads
// Pre ---
Fixed &	Fixed::operator++( void ) {

	signed long tmp;
	
	tmp = _nval + 1;

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	_nval = (int)tmp;
	return *this;
}

Fixed &	Fixed::operator--( void ) {
	
	signed long tmp;
	
	tmp = _nval - 1;

	if (tmp > std::numeric_limits<int>::max())
		tmp = std::numeric_limits<int>::max();
	else if (tmp < std::numeric_limits<int>::min())
		tmp = std::numeric_limits<int>::min();

	_nval = (int)tmp;
	return *this;
}

// Post ---
Fixed	Fixed::operator++( int ) {
	
	Fixed	copy = *this;
	operator++();
	return copy;
}

Fixed	Fixed::operator--( int ) {
	
	Fixed	copy = *this;
	operator--();
	return copy;
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


// Static functions
Fixed & Fixed::min( Fixed & a, Fixed & b ) {
	
	if (a < b)
		return a;
	else
		return b;
}

const Fixed & Fixed::min( const Fixed & a, const Fixed & b ) {

	if (a < b)
		return a;
	else
		return b;
}

Fixed & Fixed::max( Fixed & a, Fixed & b ) {

	if (a > b)
		return a;
	else
		return b;
}

const Fixed & Fixed::max( const Fixed & a, const Fixed & b ) {

	if (a > b)
		return a;
	else
		return b;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
