/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 00:25:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
ScavTrap::ScavTrap( const std::string & name )
: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	
	std::cout << "ScavTrap (" << _name << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
ScavTrap::ScavTrap( ScavTrap const & src )
: ClapTrap(src)
{
	std::cout << "ScavTrap (" << _name << ") - Copy Constructor called" << std::endl;

	return;
}

// Destructor
ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap (" << _name << ") - Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
ScavTrap &	ScavTrap::operator=(const ScavTrap & rhs)
{

	ClapTrap::operator=(rhs);
	
	std::cout << "ScavTrap (" << _name << ") - Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
void	ScavTrap::attack(const std::string& target) 
{
	// Check hp + ep
	if (!_hit_points || !_energy_points) {
		
		if (!_hit_points)
			std::cout << "ScavTrap [" << _name << "] is dead!" << std::endl;
		else
			std::cout << "ScavTrap [" << _name << "] ran out of energy!" << std::endl;

		return;
	}

	std::cout << "ScavTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;
	
	--_energy_points;

	std::cout << "ScavTrap [" << _name << "] attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	std::cout << "ScavTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;
}

void	ScavTrap::guardGate( void ) 
{
	// Check hp
	if (!_hit_points) {
	
		std::cout << "ScavTrap [" << _name << "] is dead!" << std::endl;
		return;
	}

	std::cout << "ScavTrap [" << _name << "] is now in Gate keeper mode!" << std::endl;
}
