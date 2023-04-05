/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/12 00:35:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "===== CONSTRUCTORS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::cout << "----- DEFAULT -----" << std::endl;

		std::string	str1 = "Snappy";
		DiamondTrap	snappy(str1);
		
		std::cout << "----- COPY -----" << std::endl;
		
		DiamondTrap	slappy(snappy);

		std::cout << "----- COPY ASSIGNMENT -----" << std::endl;

		std::string	str2 = "Trappy";
		std::string	str3 = "Clappy";
		DiamondTrap	clappy(str2);
		clappy = DiamondTrap(str3);

		std::cout << "----- ----- -----" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "===== FUNCTIONS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::string	str = "Zhappy";
		std::string	target = "Pleb";
		DiamondTrap	zhappy(str);
		
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
		DiamondTrap	flappy(str);
		
		std::cout << "----- HIFIVE -----" << std::endl;

		flappy.highFivesGuys();

		std::cout << "----- ENERGY -----" << std::endl;
	
		for (int i=0; i<53; ++i) {
			
			flappy.attack(target);
		}

		std::cout << "----- DAMAGE -----" << std::endl;
		
		for (int i=0; i<5; ++i) {
			
			flappy.takeDamage(50);
		}

		std::cout << "----- WHOAMI -----" << std::endl;
		
		flappy.whoAmI();

		std::cout << "----- ----- -----" << std::endl;
	}

	return 0;
}
