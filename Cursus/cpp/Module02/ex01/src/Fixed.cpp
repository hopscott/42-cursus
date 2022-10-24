/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 17:59:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _nval(0) {

	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;

	return;
}

Fixed::Fixed(int const i) {

	std::cout << "Int constructor called" << std::endl;

	_nval = i * (1 << _nfract_bits);

	return;
}

Fixed::Fixed(float const f) {

	std::cout << "Float constructor called" << std::endl;

	_nval = roundf(f * (1 << _nfract_bits));

	return;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

    return;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs) {
		
		setRawBits(rhs.getRawBits());
	}

    return *this;
}

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

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
