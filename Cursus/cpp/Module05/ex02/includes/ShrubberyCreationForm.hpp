/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:27:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {

	private:

		std::string		_target;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		ShrubberyCreationForm( const std::string & name, const size_t grade_to_sign, const size_t grade_to_execute );

		// Copy Constructor
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
	
		// Destructor
		virtual ~ShrubberyCreationForm( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		ShrubberyCreationForm &	operator=(const ShrubberyCreationForm & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Override pure virtual function
		void		executeForm(ShrubberyCreationForm const & form) const;
		
		// --------------- EXCEPTIONS ---------------

		class GradeTooHighException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("EXCEPTION - Grade cannot be higher than 1!");
				}
		};

		class GradeTooLowException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("EXCEPTION - Grade needs to be higher than ShrubberyCreationForm's grade to sign!");
				}
		};
};

#endif
