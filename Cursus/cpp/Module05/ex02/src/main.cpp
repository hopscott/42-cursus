/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 18:22:09 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl << std::endl;

	Bureaucrat					jimmy("Jimmy", 3);
	Bureaucrat					stan("Stan", 150);
	ShrubberyCreationForm		shrub("Home");
	RobotomyRequestForm			robot("Nigel");
	PresidentialPardonForm		pres("Smithers");

	std::cout << std::endl << "--- Descriptions ---" << std::endl << std::endl;

	std::cout << jimmy << std::endl;
	std::cout << stan << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pres << std::endl;

	std::cout << std::endl << "=== EXECUTING UNSIGNED FORMS === " << std::endl;

	std::cout << std::endl << "--- ShrubberyCreationForm ---" << std::endl << std::endl;
	
	try
	{
		shrub.execute(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- RobotomyRequestForm ---" << std::endl << std::endl;

	try
	{
		robot.execute(jimmy);	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- PresidentialPardonForm ---" << std::endl << std::endl;
	
	try
	{
		pres.execute(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== SIGNING FORMS === " << std::endl;
	
	std::cout << std::endl << "--- Sign ShrubberyCreationForm - grade too low ---" << std::endl << std::endl;

	try
	{
		shrub.signForm(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Sign RobotomyRequestForm - grade too low ---" << std::endl << std::endl;

	try
	{
		robot.signForm(stan);	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Sign PresidentialPardonForm - grade too low ---" << std::endl << std::endl;
	
	try
	{
		pres.signForm(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Sign all forms ---" << std::endl << std::endl;

	try
	{
		shrub.signForm(jimmy);
		robot.signForm(jimmy);
		pres.signForm(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== EXECUTING SIGNED FORMS === " << std::endl;


	std::cout << std::endl << "--- Execute ShrubberyCreationForm - grade too low ---" << std::endl << std::endl;

	try
	{
		shrub.execute(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Execute RobotomyRequestForm - grade too low ---" << std::endl << std::endl;

	try
	{
		robot.execute(stan);	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Execute PresidentialPardonForm - grade too low ---" << std::endl << std::endl;
	
	try
	{
		pres.execute(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Execute all forms ---" << std::endl << std::endl;

	try
	{
		std::cout << std::endl << "--- ShrubberyCreationForm ---" << std::endl << std::endl;
		shrub.execute(jimmy);

		std::cout << std::endl << "--- RobotomyRequestForm ---" << std::endl << std::endl;
		for (int i=0; i<6; ++i)
		{
			robot.execute(jimmy);
		}
		
		std::cout << std::endl << "--- PresidentialPardonForm ---" << std::endl << std::endl;
		pres.execute(jimmy);
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;

	return 0;
}
