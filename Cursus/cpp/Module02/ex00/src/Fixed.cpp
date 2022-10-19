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

    n_val = 0;
	return;
}

Fixed::Fixed(const Fixed &fixed) {

    _member = new Fixed;
    _member->n_val = fixed.n_val;
	return;
}

Fixed::~Fixed(void) {
    
    delete member;
    return;
}

Fixed & Fixed::operator=(const Fixed & rhs) {
    
    if (this == &rhs)
        return *this;
    
}
