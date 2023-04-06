/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 23:03:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

template< typename T >
void	swap(T& a, T& b)
{
	T	tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template< typename T >
T	min(const T& a, const T& b)
{
	if (a < b)
		return a;
	else
		return b;
}

template< typename T >
T	max(const T& a, const T& b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
