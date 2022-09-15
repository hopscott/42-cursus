/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/15 13:37:30 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) {
	
	std::cout << "Constructor called - HumanA ";
	setName(name);
	std::cout << " called " << getName();
	Weapon&	_weapon = weapon;
	std::cout << " armed with " << getWeapon().getType() << std::endl;
	return;
}

HumanA::~HumanA( void ) {
	
	std::cout << "Destructor called - HumanA called " << getName() << std::endl;
	return;
}

// =========
//  Setters
// =========

void	HumanA::setName( std::string name ) {

	_name = name;
}

void	HumanA::setWeapon( Weapon& weapon ) {

	_weapon = weapon;
}

// =========
//  Getters
// =========

const std::string&	HumanA::getName( void ) const {

	const std::string&	nameREF = _name;
	return nameREF;
}

const Weapon&	HumanA::getWeapon( void ) const {

	const Weapon&	weaponREF = _weapon;
	return weaponREF;
}

// =========
//  Others
// =========

void	HumanA::attack( void ) const {

	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}
