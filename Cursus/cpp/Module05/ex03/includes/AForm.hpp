/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 18:23:53 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

class Bureaucrat;

# include "Bureaucrat.hpp"

class AForm {

	private:

		const std::string	_name;
		bool				_is_signed;
		const size_t		_grade_to_sign;
		const size_t		_grade_to_execute;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		AForm( const std::string & name, const size_t grade_to_sign, const size_t grade_to_execute );

		// Copy Constructor
		AForm( AForm const & src );
	
		// Destructor
		virtual ~AForm( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		AForm &	operator=(const AForm & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		size_t				getGradeToSign(void) const;
		size_t				getGradeToExecute(void) const;
		
		void				beSigned(const Bureaucrat & bcrat);
		void				signForm(const Bureaucrat & bcrat);
		bool				isExecutable(Bureaucrat const & executor) const;

		// Abstract pure virtual functions
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
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
					return ("[GradeTooLowException] - Grade needs to be higher than Form's grade to sign!");
				}
		};

		class ExecutingUnsignedFormException: public std::exception {
			
			public:

				virtual const char* what(void) const throw()
				{
					return ("[ExecutingUnsignedFormException] - Form needs to be signed in order to execute!");
				}
		};
};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif
