/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/09/13 17:26:36 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {

	public:

		Zombie( void );
		~Zombie( void );

		void		announce( void );
		void		setName( std::string name );
		std::string	getName( void ) const;

	private:

		std::string	_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
