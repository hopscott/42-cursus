/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/09/15 13:37:32 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class HumanA {

	public:

		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );

		void			setName( std::string name );
		void			setWeapon( Weapon& weapon );

		const std::string&	getName( void ) const;
		const Weapon&		getWeapon( void ) const;

		void			attack( void ) const;

	private:

		std::string	_name;
		Weapon&		_weapon;

};

#endif
