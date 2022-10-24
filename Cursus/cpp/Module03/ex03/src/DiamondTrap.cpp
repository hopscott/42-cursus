/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 01:37:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
FragTrap::FragTrap( std::string & name )
: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	
	std::cout << "FragTrap (" << _name << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
FragTrap::FragTrap( FragTrap const & src )
: ClapTrap(src)
{
	std::cout << "FragTrap (" << _name << ") - Copy Constructor called" << std::endl;

	return;
}

// Destructor
FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap (" << _name << ") - Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
FragTrap &	FragTrap::operator=(const FragTrap & rhs)
{

	ClapTrap::operator=(rhs);
	
	std::cout << "FragTrap (" << _name << ") - Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
void	FragTrap::highFivesGuys( void ) 
{
	// Check hp
	if (!_hit_points) {
	
		std::cout << "FragTrap [" << _name << "] is dead!" << std::endl;
		return;
	}

	std::cout << "FragTrap [" << _name << "] Come on guys lets high five (☞ ͡° ͜ʖ ͡°)☞ ✋" << std::endl;
}
