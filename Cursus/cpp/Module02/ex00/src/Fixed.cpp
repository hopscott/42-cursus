/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 17:59:12 by swillis          ###   ########.fr       */
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

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;

    return;
}

Fixed &	Fixed::operator=(const Fixed & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs) {
		
		_nval = rhs._nval;
	}

    return *this;
}

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return _nval;
}

void	Fixed::setRawBits( int const raw ) {

	_nval = raw;
}
