/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scottwillis <scottwillis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/13 17:27:27 by scottwillis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	
	std::cout << "Constructor called - Zombie" << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	
	std::cout << "Destructor called - Zombie named " << getName() << std::endl;
	return;
}

void	Zombie::announce( void ) {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {

	_name = name;
}

std::string	Zombie::getName( void ) const {

	return _name;
}
