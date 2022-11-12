/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 00:33:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
DiamondTrap::DiamondTrap( const std::string & name )
: ClapTrap(name + "_clap_name", 100, 50, 30), FragTrap(name), ScavTrap(name), _name(name) 
{
	std::cout << "DiamondTrap (" << _name << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
DiamondTrap::DiamondTrap( DiamondTrap const & src )
: ClapTrap(src._name + "_clap_name", 100, 50, 30), FragTrap(src._name), ScavTrap(src._name), _name(src._name) 
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
	std::cout << "DiamondTrap [" << _name << "] --> ClapTrap [" << ClapTrap::_name << "]" << std::endl;
}
