/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 22:14:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Bureaucrat::Bureaucrat( const std::string & name, const size_t grade )
: _name(name), _grade(grade)
{

	if (_grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (_grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Bureaucrat::Bureaucrat( Bureaucrat const & src )
: _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;

	return;
}

// Destructor
Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & rhs)
{

	if (this != &rhs)
	{
		//name cannot be modified as const so copy other attributes such as grade
		_grade = rhs._grade;
	}
	
	std::cout << "Bureaucrat Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
const std::string &	Bureaucrat::getName(void) const
{
	return _name;
}

size_t				Bureaucrat::getGrade(void) const
{
	return _grade;
}

void				Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else
	{
		--_grade;
	}
}

void				Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	else
	{
		++_grade;
	}
}

void				Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << *this << " couldn't execute form " << form << std::endl;
		std::cout << e.what() << std::endl;
	}

}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
