/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 01:19:19 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "===== CONSTRUCTORS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::cout << "----- DEFAULT -----" << std::endl;

		std::string	str1 = "Snappy";
		ScavTrap	snappy(str1);
		
		std::cout << "----- COPY -----" << std::endl;
		
		ScavTrap	slappy(snappy);

		std::cout << "----- COPY ASSIGNMENT -----" << std::endl;

		std::string	str2 = "Trappy";
		std::string	str3 = "Clappy";
		ScavTrap	clappy(str2);
		clappy = ScavTrap(str3);

		std::cout << "----- ----- -----" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "===== FUNCTIONS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::string	str = "Zhappy";
		std::string	target = "Pleb";
		ScavTrap	zhappy(str);
		
		std::cout << "----- HITS -----" << std::endl;
		
		zhappy.attack(target);
		zhappy.beRepaired(1);	
		zhappy.takeDamage(100);
		zhappy.attack(target);
		zhappy.takeDamage(1);
		zhappy.attack(target);
		zhappy.attack(target);

		std::cout << "----- ----- -----" << std::endl;
	}

	std::cout << std::endl << std::endl;

	{	

		std::string	str = "Flappy";
		std::string	target = "Dom";
		ScavTrap	flappy(str);
		
		std::cout << "----- GATE -----" << std::endl;
		
		flappy.guardGate();
		
		std::cout << "----- ENERGY -----" << std::endl;
	
		for (int i=0; i<53; ++i) {
			
			flappy.attack(target);
		}

		flappy.guardGate();

		std::cout << "----- DAMAGE -----" << std::endl;
		
		for (int i=0; i<5; ++i) {
			
			flappy.takeDamage(50);
		}
		
		flappy.guardGate();

		std::cout << "----- ----- -----" << std::endl;
	}

	return 0;
}
