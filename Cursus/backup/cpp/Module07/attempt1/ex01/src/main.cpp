/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 23:55:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	iprint(const int& n)
{
	std::cout << "Printing " RED "int: " << n << RESET << std::endl;
}

void	fprint(const float& f)
{
	std::cout << "Printing " GREEN "float: " << f << RESET << std::endl;
}

void	dprint(const double& d)
{
	std::cout << "Printing " YELLOW "double: " << d << RESET << std::endl;
}

int main( void ) {
	
	int		itab[] = { 1, 2, 3 };
	float	ftab[] = { 0.1f, 0.02f, 0.03f };
	double	dtab[3];
	
	void (*ptr)(const int&) = NULL;
	
	iter(itab, 3, ptr);

	ptr = &iprint;
	
	iter(itab, 3, ptr);
	iter(ftab, 3, fprint);
	iter(dtab, 3, dprint);

	return 0;
}
