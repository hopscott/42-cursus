/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:04:04 by swillis           #+#    #+#             */
/*   Updated: 2022/12/19 00:09:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>
# include <limits>
# include <functional>

# include "pair.hpp"

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
	
	// https://stackoverflow.com/questions/43571962/how-is-stdis-integral-implemented
	
	// template <typename T>
	// struct is_integral 

	// template <>
	// struct is_integral<bool>
	
	// template <>
	// struct is_integral<char>;
	
	// template <>
	// struct is_integral<signed char>
	
	// template <>
	// struct is_integral<unsigned char>
	
	// template <>
	// struct is_integral<short>
	
	// template <>
	// struct is_integral<unsigned short>
	
	// template <>
	// struct is_integral<int>
	
	// template <>
	// struct is_integral<unsigned int>
	
	// template <>
	// struct is_integral<long>
	
	// template <>
	// struct is_integral<unsigned long>
	
	// template <>
	// struct is_integral<long long>
	
	// template <>
	// struct is_integral<unsigned long long>
	
	// === EQUAL ===
	
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
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

	// === MAKE PAIR ===
		
	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return ft::pair<T1, T2>(t, u);
	}
};

#endif
