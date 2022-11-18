/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:28:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target )
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{

	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
: Form("ShrubberyCreationForm", 145, 137), _target(src.target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;

	return;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
ShrubberyCreationForm &	ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{

	if (this != &rhs)
	{
		_target(src.target)
	}
	
	std::cout << "ShrubberyCreationForm Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------

void		ShrubberyCreationForm::executeForm(Form const & form) const
{
	// Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres ASCII à l’intérieur.
}
