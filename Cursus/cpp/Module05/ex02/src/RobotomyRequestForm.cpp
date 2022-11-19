/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/18 21:28:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm( const std::string & target )
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{

	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	
	return;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
: AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;

	return;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	
	return;
}

// --------------- OPERATOR OVERLOADS ---------------

// Copy Assignment Operator Overload
RobotomyRequestForm &	RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{

	if (this != &rhs)
	{
		_target = rhs._target;
	}
	
	std::cout << "RobotomyRequestForm Copy Assignment Operator called" << std::endl;

	return *this;
}

// --------------- FUNCTIONS ---------

// Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée avec succès 50% du temps. 
// Dans le cas contraire, informe que l’opération a échoué.

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	if (!isExecutable(executor))
	{
		std::cout << "[ ERROR ]" << std::endl << "Executor: " << executor << " cannot execute Form: " << *this << std::endl << std::endl;
		return;
	}

	std::cout << "*DRILLING NOISES*" << std::endl;
	
	static const size_t numIdeas = *(&ideas + 1) - ideas;
	static bool	is_seeded = false;

	if (!is_seeded)
	{
		std::srand(std::time(NULL) * getpid());
		is_seeded = true;
	}

	if (std::rand() % 2)
		std::cout << _target << " has been successfully robotomised!" << std::endl;
	else
		std::cout << _target << " has failed to be robotomised!" << std::endl;
}
