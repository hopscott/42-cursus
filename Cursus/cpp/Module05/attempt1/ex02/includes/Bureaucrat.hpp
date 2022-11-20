/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 18:41:07 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class AForm;

# include "AForm.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat {

	private:

		const std::string	_name;
		size_t				_grade;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Bureaucrat( const std::string & name, const size_t grade );

		// Copy Constructor
		Bureaucrat( Bureaucrat const & src );
	
		// Destructor
		~Bureaucrat( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Bureaucrat &	operator=(const Bureaucrat & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &	getName(void) const;
		size_t				getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				executeForm(AForm const & form);
		
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
					return ("[GradeTooLowException] - Grade cannot be lower than 150!");
				}
		};
};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );



#endif
