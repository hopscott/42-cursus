/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:04:04 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 22:52:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>
# include <limits>
# include <functional>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"

namespace ft
{

	// === ITERATOR TRAITS ===

	// https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait

	template< typename Iterator >
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	// === ENABLE IF ===

	// === IS INTEGRAL ===
	
	// === EQUAL ===
	
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {

		while (first1 != last1) 
		{
			if (*first1 != *first2) 
			{
				return false;
			}
			++first1;
			++first2;
		}

		return true;
	}

	// === PAIR ===
	
	// === MAKE PAIR ===

};

#endif
