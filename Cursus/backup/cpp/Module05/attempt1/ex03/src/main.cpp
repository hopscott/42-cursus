/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 22:28:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl << std::endl;

	Intern 						someRandomIntern;
	AForm* 						rrf;
	
	Bureaucrat					jimmy("Jimmy", 3);
	Bureaucrat					stan("Stan", 150);

	std::cout << std::endl << "--- Descriptions ---" << std::endl << std::endl;

	std::cout << jimmy << std::endl;
	std::cout << stan << std::endl;

	std::cout << std::endl << "=== INTERN - MAKING FORMS === " << std::endl;

	std::cout << std::endl << "=== Non existant ===" << std::endl << std::endl;
	
	rrf = someRandomIntern.makeForm("mumbo jumbo", "Richard");
	
	// **********************************************************************************
	// **********************************************************************************
	
	std::cout << std::endl << std::endl << "*** ShrubberyCreationForm ***" << std::endl << std::endl << std::endl;
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");

	std::cout << std::endl << "--- Sign - grade too low ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Execute - unsigned ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Sign ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Execute - signed ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Destructor ---" << std::endl << std::endl;

	// delete otherwise leaks
	delete rrf;
	
	// **********************************************************************************
	// **********************************************************************************
	
	std::cout << std::endl << std::endl << "*** RobotomyRequestForm ***" << std::endl << std::endl << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	
	std::cout << std::endl << "--- Sign - grade too low ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Execute - unsigned ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Sign ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Execute - signed ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Destructor ---" << std::endl << std::endl;

	// delete otherwise leaks
	delete rrf;

	// **********************************************************************************
	// **********************************************************************************

	std::cout << std::endl << std::endl << "*** PresidentialPardonForm ***" << std::endl << std::endl << std::endl;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	
	std::cout << std::endl << "--- Sign - grade too low ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(stan);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Execute - unsigned ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Sign ---" << std::endl << std::endl;

	try
	{
		rrf->signForm(jimmy);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "--- Execute - signed ---" << std::endl << std::endl;

	try
	{
		jimmy.executeForm(*rrf);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Destructor ---" << std::endl << std::endl;

	// delete otherwise leaks
	delete rrf;

	// **********************************************************************************
	// **********************************************************************************

	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;

	return 0;
}
