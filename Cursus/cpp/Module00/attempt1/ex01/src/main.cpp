/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/09/10 22:44:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


int	main( void )
{
	std::string	str;
	PhoneBook	phonebook;

	while (std::cin)
	{
		std::cout << "Enter a command [ADD, SEARCH or EXIT]: " << std::endl;
		std::getline (std::cin, str);
		if (str == "ADD")
			phonebook.addNewContact();
		if (str == "EXIT")
			break ;
	}
	return (0);
}
