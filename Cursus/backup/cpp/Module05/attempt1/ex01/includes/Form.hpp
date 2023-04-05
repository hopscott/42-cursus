/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 21:31:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "Bureaucrat.hpp"

class Form {

	private:

		const std::string	_name;
		bool				_is_signed;
		const size_t		_grade_to_sign;
		const size_t		_grade_to_execute;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Form( const std::string & name, const size_t grade_to_sign, const size_t grade_to_execute );

		// Copy Constructor
		Form( Form const & src );
	
		// Destructor
		~Form( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Form &	operator=(const Form & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		size_t				getGradeToSign(void) const;
		size_t				getGradeToExecute(void) const;
		
		void				beSigned(const Bureaucrat & bcrat);
		void				signForm(const Bureaucrat & bcrat);
		
		// --------------- EXCEPTIONS ---------------

		class GradeTooLowException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("[GradeTooLowException] - Grade needs to be higher than Form's grade to sign!");
				}
		};
};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif
