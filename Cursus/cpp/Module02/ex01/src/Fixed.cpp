/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/19 17:37:45 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {

	std::cout << "Default constructor called" << std::endl;
    _nval = 0;

	return;
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::Fixed(int const i) {

	int	x;

	std::cout << "Int constructor called" << std::endl;

	x = i * (2 ^ _nfract_bits);
	setRawBits(x);

	return;
}

Fixed::Fixed(float const f) {

	int	x;

	std::cout << "Float constructor called" << std::endl;

	x = f * (2 ^ _nfract_bits);
	setRawBits(x);

	return;
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

    return;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;

    if (this == &rhs)
        return *this;

    setRawBits(rhs.getRawBits());

    return *this;
}

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return _nval;
}

void	Fixed::setRawBits( int const raw ) {

	_nval = raw;
}

float	Fixed::toFloat( void ) const {

	return (_nval);
}

int		Fixed::toInt( void ) const {

	return (_nval);
}

// https://stackoverflow.com/questions/67517939/how-to-connect-the-theory-of-fixed-point-numbers-and-its-practical-implementatio
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.getRawBits();
	return o;
}
