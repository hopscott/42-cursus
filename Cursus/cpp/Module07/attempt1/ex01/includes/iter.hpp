/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 23:54:15 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>
# include <cmath>

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define RESET		"\x1b[0m"

template< typename T >
void	iter(const T* address, const std::size_t length, void (*func)(const T&))
{
	if ((!address) || (!func))
		return;

	for (std::size_t i=0; i<length; ++i)
	{
		func(address[i]);
	}
}

template< typename T >
void	iter(T* address, const std::size_t length, void (*func)(T&))
{
	if ((!address) || (!func))
		return;

	for (std::size_t i=0; i<length; ++i)
	{
		func(address[i]);
	}
}

#endif
