/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 23:09:48 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class AForm;

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

	private:

		enum {
			SHRUBBERY,
			ROBOTOMY,
			PRESIDENTIAL,
			FORMS
		};

		typedef AForm * (Intern::*PtrMemFunc) (const std::string & target);
		static const PtrMemFunc	_pmf[FORMS];
		static const char*		_formNames[FORMS];

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Intern( void );

		// Copy Constructor
		Intern( Intern const & src );
	
		// Destructor
		~Intern( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Intern &	operator=(const Intern & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		AForm *		makeForm( const std::string & name, const std::string & target );
		AForm *		makeShrubberyCreationForm( const std::string & target );
		AForm *		makeRobotomyRequestForm( const std::string & target );
		AForm *		makePresidentialPardonForm( const std::string & target );

};

#endif
