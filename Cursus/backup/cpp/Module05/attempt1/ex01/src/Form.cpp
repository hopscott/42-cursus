/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 21:33:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
Form::Form( const std::string & name, const size_t grade_to_sign, const size_t grade_to_execute )
: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{

	if ((_grade_to_sign < 1) || (_grade_to_execute < 1))
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if ((_grade_to_sign > 150) || (_grade_to_execute > 150))
	{
		throw Bureaucrat::GradeTooLowException();
	}
	
	std::cout << "Form Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
Form::Form( Form const & src )
: _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	std::cout << "Form Copy Constructor called" << std::endl;

	return;
}

// Destructor
Form::~Form( void )
{
	std::cout << "Form Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
Form &	Form::operator=(const Form & rhs)
{

	if (this != &rhs)
	{
		//const attributes cannot be copied so copy other attributes such as is_signed
		_is_signed = rhs._is_signed;
	}
	
	std::cout << "Form Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
const std::string &	Form::getName(void) const
{
	return _name;
}

bool				Form::getIsSigned(void) const
{
	return _is_signed;
}

size_t				Form::getGradeToSign(void) const
{
	return _grade_to_sign;
}

size_t				Form::getGradeToExecute(void) const
{
	return _grade_to_execute;
}

void				Form::beSigned(const Bureaucrat & bcrat)
{
	if (bcrat.getGrade() > _grade_to_sign)
	{
		throw GradeTooLowException();
	}

	signForm(bcrat);
}

void				Form::signForm(const Bureaucrat & bcrat)
{
	if (bcrat.getGrade() > _grade_to_sign)
	{
		std::cout << bcrat << " couldn't sign form " << *this << " because grade too low!" << std::endl;
		throw GradeTooLowException();
	}
	
	if (_is_signed == false)
	{
		_is_signed = true;
		std::cout << bcrat << " signed " << *this << std::endl;
	}
	else
		std::cout << bcrat << " couldn't sign form " << *this << " because already signed!" << std::endl;

}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{

	if (rhs.getIsSigned())
		o << rhs.getName() << " Form (signed) [SIGN=" << rhs.getGradeToSign() << "] [EXECUTE=" << rhs.getGradeToExecute() << "]";
	else
		o << rhs.getName() << " Form (not signed) [SIGN=" << rhs.getGradeToSign() << "] [EXECUTE=" << rhs.getGradeToExecute() << "]";

	return o;
}
