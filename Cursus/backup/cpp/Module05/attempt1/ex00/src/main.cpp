/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 21:42:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl;

	std::cout << std::endl << "--- Grade too high ---" << std::endl << std::endl;

	try
	{
		Bureaucrat	snooperr("Snoop", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Grade too low ---" << std::endl << std::endl;
	
	try
	{
		Bureaucrat	eltonerr("Elton", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Descriptions ---" << std::endl << std::endl;

	Bureaucrat	snoop("Snoop", 1);
	Bureaucrat	elton("Elton", 150);
	Bureaucrat	john("John", 33);

	std::cout << std::endl;

	std::cout << snoop << std::endl;
	std::cout << elton << std::endl;
	std::cout << john << std::endl;


	std::cout << std::endl << "=== GRADES - NO ISSUES === " << std::endl << std::endl;
	
	try
	{
		std::cout << john << std::endl;
		
		john.incrementGrade();
		john.incrementGrade();
		john.incrementGrade();
		
		std::cout << john << std::endl;

		john.decrementGrade();

		std::cout << john << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== GRADES - TOO HIGH === " << std::endl << std::endl;

	try
	{
		std::cout << snoop << std::endl;
		
		snoop.incrementGrade();
		
		std::cout << snoop << std::endl;

		snoop.decrementGrade();

		std::cout << snoop << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== GRADES - TOO LOW === " << std::endl << std::endl;

	try
	{
		std::cout << elton << std::endl;
		
		elton.decrementGrade();
		
		std::cout << elton << std::endl;

		elton.incrementGrade();

		std::cout << elton << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;

	return 0;
}
