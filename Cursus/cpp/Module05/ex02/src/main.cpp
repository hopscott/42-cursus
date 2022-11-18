/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 20:25:07 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl << std::endl;

	Bureaucrat	wazowski("Wazowski", 33);
	Form		ws_2319("White Sock 23-19", 30, 10);
	Form		ws_2320("Green Sock 23-20", 30, 10);
	Form		ws_2321("Black Sock 23-21", 30, 10);

	std::cout << std::endl << "=== SIGNING FORMS === " << std::endl << std::endl;
	
	try
	{
		std::cout << ws_2319 << std::endl;
		std::cout << ws_2320 << std::endl;
		std::cout << ws_2321 << std::endl;

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
