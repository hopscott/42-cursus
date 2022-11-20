/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:27:50 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <ctime>
# include <cstdlib>
# include <unistd.h>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {

	private:

		std::string		_target;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		RobotomyRequestForm( const std::string & target );

		// Copy Constructor
		RobotomyRequestForm( RobotomyRequestForm const & src );
	
		// Destructor
		~RobotomyRequestForm( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		RobotomyRequestForm &	operator=(const RobotomyRequestForm & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Override pure virtual function
		void		execute(Bureaucrat const & executor) const;
		
		// --------------- EXCEPTIONS ---------------

		class GradeTooHighException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("[GradeTooHighException] - Grade cannot be higher than 1!");
				}
		};

		class GradeTooLowException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("[GradeTooLowException] - Grade needs to be higher than RobotomyRequestForm's grade to sign!");
				}
		};
};

#endif
