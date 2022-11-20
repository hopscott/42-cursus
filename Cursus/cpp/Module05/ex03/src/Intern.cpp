/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 20:55:07 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Intern::Intern( void )
{
	std::cout << "Intern Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Intern::Intern( Intern const & src )
{
	(void)src;
	
	std::cout << "Intern Copy Constructor called" << std::endl;

	return;
}

// Destructor
Intern::~Intern( void )
{
	std::cout << "Intern Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Intern &	Intern::operator=(const Intern & rhs)
{
	(void)rhs;

	std::cout << "Intern Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
AForm *		Intern::makeForm(const std::string & name, const std::string & target)
{
	AForm *		form;
	int			n = -1;

	enum {
		SHRUBBERY,
		ROBOTOMY,
		PRESIDENTIAL,
		NCASES
	};

	const std::string	caseNames[NCASES] = {"shrubbery creation", "robotomy request",  "presidential pardon"};

	for (int i=0; i<NCASES; ++i)
	{
		if (name == caseNames[i])
			n = i;
	}

	switch (n)
	{
		case SHRUBBERY:
		
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
		
		case ROBOTOMY:
		
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;

		case PRESIDENTIAL:

			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;

		default:
		
			std::cout << "Intern could not find the Form: " << name << " to make!" << std::endl;
			return NULL;
			
	}
}
