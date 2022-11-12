/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 00:24:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class ClapTrap {

	protected:

		// Diamond Constructor
		ClapTrap(	const std::string & name, 
					unsigned int hit_points,
					unsigned int energy_points,
					unsigned int attack_damage );

		std::string 	_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		ClapTrap( const std::string & name );

		// Copy Constructor
		ClapTrap( ClapTrap const & src );
	
		// Destructor
		~ClapTrap( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		ClapTrap &	operator=(const ClapTrap & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

		// Static functions

};

#endif
