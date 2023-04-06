/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:28:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm( const std::string & target )
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{

	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
: AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;

	return;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
PresidentialPardonForm &	PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{

	if (this != &rhs)
	{
		_target = rhs._target;
	}
	
	std::cout << "PresidentialPardonForm Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------

// Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée avec succès 50% du temps. 
// Dans le cas contraire, informe que l’opération a échoué.

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if (!isExecutable(executor))
	{
		std::cout << "[ ERROR ]" << std::endl << "Executor: " << executor << " cannot execute Form: " << *this << std::endl << std::endl;
		throw GradeTooLowException();
		return;
	}

	std::cout << _target << " has been pardonned graciously by Zaphod Beeblebrox." << std::endl;
}
