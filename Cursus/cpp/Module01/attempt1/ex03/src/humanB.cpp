/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 01:15:24 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( const std::string& name ) 
: _name(name) {

	std::cout << "Constructor called - HumanB called " << getName() << std::endl;
	_weapon = NULL;
}

HumanB::~HumanB( void ) {

	std::cout << "Destructor called - HumanB called " << getName() << std::endl;
}

// =========
//  Setters
// =========

void	HumanB::setName( std::string name ) {

	_name = name;
}

void	HumanB::setWeapon( Weapon& weapon ) {

	_weapon = &weapon;
}

// =========
//  Getters
// =========

const std::string&	HumanB::getName( void ) const {

	const std::string&	nameREF = _name;
	return nameREF;
}

Weapon*	HumanB::getWeapon( void ) const {

	Weapon*	weaponPTR = _weapon;
	return weaponPTR;
}

// =========
//  Others
// =========

void	HumanB::attack( void ) const {

	Weapon*	weapon;

	std::cout << getName() << " attacks with their "; 
	weapon = getWeapon();
	if (weapon == NULL)
		std::cout << "non-existant weapon" << std::endl;
	else
		std::cout << weapon->getType() << std::endl;
}
