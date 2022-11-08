/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 00:41:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
ClapTrap::ClapTrap( std::string & name )
: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap (" << _name << ") - Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
ClapTrap::ClapTrap( ClapTrap const & src )
: _name(src._name), _hit_points(src._hit_points), _energy_points(src._energy_points), _attack_damage(src._attack_damage)
{
	std::cout << "ClapTrap (" << _name << ") - Copy Constructor called" << std::endl;

	return;
}

// Destructor
ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap (" << _name << ") - Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
ClapTrap &	ClapTrap::operator=(const ClapTrap & rhs)
{

	if (this != &rhs)
	{
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
	}
	
	std::cout << "ClapTrap (" << _name << ") - Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
void	ClapTrap::attack(const std::string& target) 
{
	// Check hp + ep
	if (!_hit_points || !_energy_points) {
		
		if (!_hit_points)
			std::cout << "ClapTrap [" << _name << "] is dead!" << std::endl;
		else
			std::cout << "ClapTrap [" << _name << "] ran out of energy!" << std::endl;

		return;
	}

	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;
	
	--_energy_points;

	std::cout << "ClapTrap [" << _name << "] attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	// Check hp + ep
	if (!_hit_points || !_energy_points) {
		
		if (!_hit_points)
			std::cout << "ClapTrap [" << _name << "] is dead!" << std::endl;
		else
			std::cout << "ClapTrap [" << _name << "] ran out of energy!" << std::endl;

		return;
	}

	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;

	--_energy_points;

	// Overflow protection
	if (_hit_points + amount > std::numeric_limits<unsigned int>::max())
		_hit_points = std::numeric_limits<unsigned int>::max();
	else
		_hit_points += amount;

	std::cout << "ClapTrap [" << _name << "] repairs itself by " << amount << "HP!" << std::endl;
	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	// Check hp + ep
	if (!_hit_points) {

		std::cout << "ClapTrap [" << _name << "] is dead!" << std::endl;
		return;
	}
	
	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;
	std::cout << "ClapTrap [" << _name << "] takes damage of " << amount << "HP!" << std::endl;

	// Overflow protection
	if (_hit_points < amount)
		_hit_points = 0;
	else
		_hit_points -= amount;
		
	std::cout << "ClapTrap [" << _name << "] -> HP(" << _hit_points << ") EP(" << _energy_points << ")" << std::endl;

}
