/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 21:47:51 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl;

	std::cout << std::endl << "--- Grades too high ---" << std::endl << std::endl;

	try
	{
		Form		ws_2321("Black Sock 23-21", 1, 1);
		Form		ws_2321err("Black Sock 23-21", 0, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		ws_2320("Green Sock 23-20", 1, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		ws_2321("Black Sock 23-21", 0, 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Grades too low ---" << std::endl << std::endl;

	try
	{
		Form		ws_2321("Black Sock 23-21", 150, 150);
		Form		ws_2321err("Black Sock 23-21", 151, 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		ws_2320("Green Sock 23-20", 150, 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		ws_2321("Black Sock 23-21", 151, 150);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Descriptions ---" << std::endl << std::endl;

	Bureaucrat	wazowski("Wazowski", 33);
	Form		ws_2319("White Sock 23-19", 30, 10);
	Form		ws_2320("Green Sock 23-20", 30, 10);
	Form		ws_2321("Black Sock 23-21", 30, 10);

	std::cout << std::endl;

	std::cout << wazowski << std::endl;
	std::cout << ws_2319 << std::endl;
	std::cout << ws_2320 << std::endl;
	std::cout << ws_2321 << std::endl;

	std::cout << std::endl << "=== SIGNING FORMS === " << std::endl;
	
	try
	{
		std::cout << std::endl << "--- Increment lvl ---" << std::endl << std::endl;
		std::cout << wazowski << std::endl;
		wazowski.incrementGrade();
		wazowski.incrementGrade();
		wazowski.incrementGrade();
		std::cout << wazowski << std::endl;

		std::cout << std::endl << "--- Sign form - same lvl ---" << std::endl << std::endl;

		ws_2319.signForm(wazowski);

		std::cout << std::endl << "--- Sign form - resign form ---" << std::endl << std::endl;
	
		ws_2319.signForm(wazowski);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Sign form - higher lvl ---" << std::endl << std::endl;

	try
	{	
		std::cout << wazowski << std::endl;
		wazowski.incrementGrade();
		std::cout << wazowski << std::endl;
		
		ws_2320.signForm(wazowski);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Sign form - lower lvl ---" << std::endl << std::endl;

	try
	{
		std::cout << wazowski << std::endl;
		wazowski.decrementGrade();
		wazowski.decrementGrade();
		std::cout << wazowski << std::endl;
		
		ws_2321.signForm(wazowski);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;

	return 0;
}
