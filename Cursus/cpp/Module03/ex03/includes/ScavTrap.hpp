/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 00:25:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		ScavTrap( const std::string & name );

		// Copy Constructor
		ScavTrap( ScavTrap const & src );
	
		// Destructor
		~ScavTrap( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		ScavTrap &	operator=(const ScavTrap & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void	attack(const std::string& target);
		void	guardGate( void );

		// Static functions

};

#endif
