/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/20 18:16:39 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
AForm::AForm( const std::string & name, const size_t grade_to_sign, const size_t grade_to_execute )
: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{

	if ((_grade_to_sign < 1) || (_grade_to_execute < 1))
	{
		throw GradeTooHighException();
	}
	else if ((_grade_to_sign > 150) || (_grade_to_execute > 150))
	{
		throw GradeTooLowException();
	}
	
	std::cout << "AForm Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
AForm::AForm( AForm const & src )
: _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	std::cout << "AForm Copy Constructor called" << std::endl;

	return;
}

// Destructor
AForm::~AForm( void )
{
	std::cout << "AForm Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
AForm &	AForm::operator=(const AForm & rhs)
{

	if (this != &rhs)
	{
		//const attributes cannot be copied so copy other attributes such as is_signed
		_is_signed = rhs._is_signed;
	}
	
	std::cout << "AForm Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions
const std::string &	AForm::getName(void) const
{
	return _name;
}

bool				AForm::getIsSigned(void) const
{
	return _is_signed;
}

size_t				AForm::getGradeToSign(void) const
{
	return _grade_to_sign;
}

size_t				AForm::getGradeToExecute(void) const
{
	return _grade_to_execute;
}

void				AForm::beSigned(const Bureaucrat & bcrat)
{
	if (bcrat.getGrade() < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if ((bcrat.getGrade() < LOWEST_GRADE) && (bcrat.getGrade() <= _grade_to_sign))
			signForm(bcrat);
	else
		throw GradeTooLowException();
}

void				AForm::signForm(const Bureaucrat & bcrat)
{

	if (bcrat.getGrade() < HIGHEST_GRADE)
	{
		std::cout << bcrat << " couldn't sign AForm " << *this << " because grade too high!" << std::endl;
		throw GradeTooHighException();
	}
	else if (bcrat.getGrade() > _grade_to_sign)
	{
		std::cout << bcrat << " couldn't sign AForm " << *this << " because grade too low!" << std::endl;
		throw GradeTooLowException();
	}
	
	if (_is_signed == false)
	{
		_is_signed = true;
		std::cout << bcrat << " signed " << *this << std::endl;	
	}
	else
		std::cout << bcrat << " couldn't sign AForm " << *this << " because already signed!" << std::endl;

}

bool				AForm::isExecutable(Bureaucrat const & executor) const
{
	if (_is_signed == false)
	{
		throw ExecutingUnsignedFormException();
		return false;
	}
	else if (executor.getGrade() > _grade_to_execute)
	{
		throw GradeTooLowException();
		return false;
	}
	return true;
}

// --------------- PRINTING ---------------

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{

	if (rhs.getIsSigned())
		o << rhs.getName() << " AForm (signed) [SIGN=" << rhs.getGradeToSign() << "] [EXECUTE=" << rhs.getGradeToExecute() << "]";
	else
		o << rhs.getName() << " AForm (not signed) [SIGN=" << rhs.getGradeToSign() << "] [EXECUTE=" << rhs.getGradeToExecute() << "]";

	return o;
}
