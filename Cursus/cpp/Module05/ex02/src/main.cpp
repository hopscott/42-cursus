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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTORS === " << std::endl << std::endl;

	Bureaucrat					jimmy("Jimmy", 4);
	ShrubberyCreationForm		shrub("garden");
	RobotomyRequestForm			robot("Nigel");
	PresidentialPardonForm		pres("Smithers");

	std::cout << jimmy << std::endl;


	shrub.signForm(jimmy);
	robot.signForm(jimmy);
	pres.signForm(jimmy);

	shrub.execute(jimmy);
	robot.execute(jimmy);
	pres.execute(jimmy);

	return 0;
}
