/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:27:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {

	private:

		std::string		_target;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		PresidentialPardonForm( const std::string & target );

		// Copy Constructor
		PresidentialPardonForm( PresidentialPardonForm const & src );
	
		// Destructor
		~PresidentialPardonForm( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		PresidentialPardonForm &	operator=(const PresidentialPardonForm & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Override pure virtual function
		void		execute(Bureaucrat const & executor) const;
		
		// --------------- EXCEPTIONS ---------------

		class GradeTooLowException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("[GradeTooLowException] - Grade needs to be higher than PresidentialPardonForm's grade to sign!");
				}
		};
};

#endif
