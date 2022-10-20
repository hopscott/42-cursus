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
