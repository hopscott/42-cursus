/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/17 02:12:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl << std::endl;

	Bureaucrat	snoop("Snoop", 1);
	Bureaucrat	elton("Elton", 150);
	Bureaucrat	john("John", 33);

	std::cout << std::endl << "=== GRADES - NO ISSUES === " << std::endl << std::endl;
	
	try
	{
		std::cout << john;
		
		john.incrementGrade();
		john.incrementGrade();
		john.incrementGrade();
		
		std::cout << john;

		john.decrementGrade();

		std::cout << john;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== GRADES - TOO HIGH === " << std::endl << std::endl;

	try
	{
		std::cout << snoop;
		
		snoop.incrementGrade();
		
		std::cout << snoop;

		snoop.decrementGrade();

		std::cout << snoop;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== GRADES - TOO LOW === " << std::endl << std::endl;

	try
	{
		std::cout << elton;
		
		elton.decrementGrade();
		
		std::cout << elton;

		elton.incrementGrade();

		std::cout << elton;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;

	return 0;
}
