/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:03:23 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 20:14:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

#define UINT(what) static_cast<unsigned int>((what))

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define RESET		"\x1b[0m"


Base *	generate(void)
{
	static bool	is_seeded = false;

	if (!is_seeded)
	{
		std::srand(UINT(std::time(NULL)) * UINT(getpid()));
		is_seeded = true;
	}

	int	n = std::rand();

	if ((n % 3) == 0)
	{
		std::cout << "     Generated: " RED "A" RESET << std::endl;
		return new A;
	}
	else if ((n % 3) == 1)
	{
		std::cout << "     Generated: " GREEN "B" RESET << std::endl;
		return new B;
	}
	else
	{
		std::cout << "     Generated: " YELLOW "C" RESET << std::endl;
		return new C;
	}
}

void	identify(Base* p)
{
	std::cout << "Identified PTR: ";
	
	if (dynamic_cast<A*>(p))
	{
		std::cout << RED "A" RESET;	
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << GREEN "B" RESET;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << YELLOW "C" RESET;
	}
	std::cout << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Identified REF: " RED "A" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
	}
	
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Identified REF: " GREEN "B" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
	}
	
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Identified REF: " YELLOW "C" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
	}
}
