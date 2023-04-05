/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/09/26 16:25:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class HumanB {

	public:

		HumanB( const std::string& name );
		~HumanB( void );

		void				setName( std::string name );
		void				setWeapon( Weapon& weapon );

		const std::string&	getName( void ) const;
		Weapon*				getWeapon( void ) const;

		void				attack( void ) const;

	private:

		std::string			_name;
		Weapon*				_weapon;

};

#endif
