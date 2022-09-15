/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/15 13:28:24 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	
	std::cout << "Constructor called - Weapon";
	setType(type);
	std::cout << " of type " << getType() << std::endl;
	return;
}

Weapon::~Weapon( void ) {
	
	std::cout << "Destructor called - Weapon type " << getType() << std::endl;
	return;
}

void	Weapon::setType( std::string type ) {

	_type = type;
}

const std::string&	Weapon::getType( void ) const {

	const std::string&	typeREF = _type;
	return typeREF;
}
