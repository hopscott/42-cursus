/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:04:04 by swillis           #+#    #+#             */
/*   Updated: 2022/12/17 22:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERTRAITS_H
# define ITERTRAITS_H

namespace ft
{
	// https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait
	template< typename Iterator >
	struct iterator_traits
	{
		typedef Iterator::value_type			value_type;
		typedef Iterator::difference_type		difference_type;
		typedef Iterator::reference 			reference;
		typedef Iterator::pointer 				pointer;
		typedef Iterator::iterator_category		iterator_category;
	};
};

#endif
