/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/09/14 15:56:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*horde;
	Zombie	*zombie;
	int		n;

	n = 4;
	horde = zombieHorde(n, "Dan");
	for (int i=0; i<n; i++) {
		zombie = &horde[i];
		zombie->announce();
	}
	
	delete [] horde;
	
	return (0);
}
