/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/08/15 16:08:39 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	while (1)
	{
		std::string	str;

		std::cout << "Enter a command [ADD, SEARCH or EXIT]: " << std::endl;
		std::cin >> str;
		if (str == "EXIT")
			break ;
	}
	return (0);
}
