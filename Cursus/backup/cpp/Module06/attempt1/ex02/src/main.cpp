/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 20:08:06 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int	main( void )
{
	Base*	ptr;

	for (int i=0; i<10; ++i)
	{
		ptr = generate();

		identify(ptr);
		identify(*ptr);
		
		std::cout << std::endl;
	}

    return 0;
}
