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
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
: AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
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
		_target = rhs._target;
	}
	
	std::cout << "ShrubberyCreationForm Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	(void)executor;

	// Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres ASCII à l’intérieur.

	std::string		shrub =
	"   				,@@@@@@@,                     "
	"		,,,.   ,@@@@@@/@@,  .oo8888o.             "
	"		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o        "
	"	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'        "
	"	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'         "
	"	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'          "
	"	`&%\\ ` /%&'    |.|        \\ '|8'            "
	"		|o|        | |         | |                "
	"		|.|        | |         | |                "
	"	_/_ \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_  ";

	// Output file
	std::string	filename = _target;
	filename.append("_shrubbery");
	std::ofstream   ofs(filename.c_str());
	if (!ofs) {

		std::cout << "[ ERROR ]" << std::endl << "Output file: " << filename << " could not be opened" << std::endl << std::endl;
		return;
	}

	// print into output file
	// ofs << shrub;

	std::cout << shrub << std::endl;

	ofs.close();
}
