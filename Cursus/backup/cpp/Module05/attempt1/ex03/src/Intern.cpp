/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 17:34:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*					Intern::_formNames[FORMS] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const Intern::PtrMemFunc	Intern::_pmf[FORMS] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

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

AForm *		Intern::makeShrubberyCreationForm( const std::string & target )
{
	return new ShrubberyCreationForm(target);
}

AForm *		Intern::makeRobotomyRequestForm( const std::string & target )
{
	return new RobotomyRequestForm(target);
}

AForm *		Intern::makePresidentialPardonForm( const std::string & target )
{
	return new PresidentialPardonForm(target);
}

AForm *		Intern::makeForm(const std::string & name, const std::string & target)
{
	AForm *		form;

    for (int i=0; i<FORMS; ++i)
	{
        if (_formNames[i] == name)
        {
			form = (this->*_pmf[i])(target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
        }
	}

	std::cout << "Intern could not find the Form: " << name << " to make!" << std::endl;
	return NULL;
}
