/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 21:07:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>

#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define RESET		"\x1b[0m"

template< typename C >
typename C::const_iterator	easyfind( C const & container, int n )
{
	typename C::const_iterator	it;

	it = std::find(container.begin(), container.end(), n);
	
	if (it == container.end())
	{
		throw std::exception();
	}
	
	return it;
}

#endif
