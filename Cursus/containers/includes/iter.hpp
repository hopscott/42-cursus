/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:04:04 by swillis           #+#    #+#             */
/*   Updated: 2022/12/11 18:25:00 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

// TO DO-> need to create random acces iterator class by inheriting from std::iterator?

namespace ft
{
	// https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait
	template< typename T >
	struct iterator_traits
	{
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                               value_type;
		typedef T*                              pointer;
		typedef T&                              reference;
		typedef std::ptrdiff_t                  difference_type;
	};
};

#endif
