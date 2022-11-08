/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 01:23:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "===== CONSTRUCTORS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::cout << "----- DEFAULT -----" << std::endl;

		std::string	str1 = "Snappy";
		FragTrap	snappy(str1);
		
		std::cout << "----- COPY -----" << std::endl;
		
		FragTrap	slappy(snappy);

		std::cout << "----- COPY ASSIGNMENT -----" << std::endl;

		std::string	str2 = "Trappy";
		std::string	str3 = "Clappy";
		FragTrap	clappy(str2);
		clappy = FragTrap(str3);

		std::cout << "----- ----- -----" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "===== FUNCTIONS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::string	str = "Zhappy";
		std::string	target = "Pleb";
		FragTrap	zhappy(str);
		
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
		FragTrap	flappy(str);
		
		std::cout << "----- HIFIVE -----" << std::endl;

		flappy.highFivesGuys();

		std::cout << "----- ENERGY -----" << std::endl;
	
		for (int i=0; i<103; ++i) {
			
			flappy.attack(target);
		}

		flappy.highFivesGuys();

		std::cout << "----- DAMAGE -----" << std::endl;
		
		for (int i=0; i<5; ++i) {
			
			flappy.takeDamage(50);
		}
		
		flappy.highFivesGuys();

		std::cout << "----- ----- -----" << std::endl;
	}

	return 0;
}
