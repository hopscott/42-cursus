/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/09/26 13:38:21 by swillis          ###   ########.fr       */
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

		HumanA( const std::string& name, Weapon& weapon );
		~HumanA( void );

		void				setName( std::string name );

		const std::string&	getName( void ) const;
		const Weapon&		getWeapon( void ) const;

		void				attack( void ) const;

	private:

		std::string			_name;
		Weapon&				_weapon;

};

#endif
