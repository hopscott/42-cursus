/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/09 00:50:12 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


// Make a custom claptrap protected constructor with all variables


// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
DiamondTrap::DiamondTrap( std::string & name )
: _name(name), FragTrap(name), ScavTrap(name)
{
	ClapTrap::_name = name.append("_clap_name");
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	
	std::cout << "DiamondTrap (" << _name << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
DiamondTrap::DiamondTrap( DiamondTrap const & src )
: ClapTrap(src)
{
	std::cout << "DiamondTrap (" << _name << ") - Copy Constructor called" << std::endl;

	return;
}

// Destructor
DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap (" << _name << ") - Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
DiamondTrap &	DiamondTrap::operator=(const DiamondTrap & rhs)
{

	ClapTrap::operator=(rhs);
	
	std::cout << "DiamondTrap (" << _name << ") - Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
void	DiamondTrap::whoAmI( void ) 
{
	std::cout << "DiamondTrap [" << _name << "] Come on guys lets high five (☞ ͡° ͜ʖ ͡°)☞ ✋" << std::endl;
}
