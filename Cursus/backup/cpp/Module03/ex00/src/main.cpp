/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/25 00:32:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "===== CONSTRUCTORS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::cout << "----- DEFAULT -----" << std::endl;

		std::string	str1 = "Snappy";
		ClapTrap	snappy(str1);
		
		std::cout << "----- COPY -----" << std::endl;
		
		ClapTrap	slappy(snappy);

		std::cout << "----- COPY ASSIGNMENT -----" << std::endl;

		std::string	str2 = "Trappy";
		std::string	str3 = "Clappy";
		ClapTrap	clappy(str2);
		clappy = ClapTrap(str3);

		std::cout << "----- ----- -----" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "===== FUNCTIONS =====" << std::endl;
	std::cout << std::endl;
	
	{
		std::string	str = "Zhappy";
		std::string	target = "Pleb";
		ClapTrap	zhappy(str);
		
		std::cout << "----- HITS -----" << std::endl;
		
		zhappy.attack(target);
		zhappy.beRepaired(1);	
		zhappy.takeDamage(10);
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
		ClapTrap	flappy(str);
		
		std::cout << "----- ENERGY -----" << std::endl;
	
		for (int i=0; i<13; ++i) {
			
			flappy.attack(target);
		}

		std::cout << "----- DAMAGE -----" << std::endl;
		
		for (int i=0; i<5; ++i) {
			
			flappy.takeDamage(5);
		}
		
		std::cout << "----- ----- -----" << std::endl;
	}

	return 0;
}
