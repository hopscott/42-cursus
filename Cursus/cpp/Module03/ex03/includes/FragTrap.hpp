/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 01:34:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		FragTrap( std::string & name );

		// Copy Constructor
		FragTrap( FragTrap const & src );
	
		// Destructor
		~FragTrap( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		FragTrap &	operator=(const FragTrap & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void	highFivesGuys(void);

		// Static functions

};

#endif
