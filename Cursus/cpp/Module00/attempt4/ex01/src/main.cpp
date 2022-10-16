/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/09/23 14:27:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
# include "PhoneBook.hpp"

int	main( void )
{
	std::string	str;
	PhoneBook	phonebook;

	while (std::cin)
	{
		std::cout << "Enter a command [\"ADD\", \"SEARCH\" or \"EXIT\"]: " << std::endl;
		std::getline (std::cin, str);
		if (!containsGraph(str) || containsNonPrintables(str))
			continue;
		streamClean(str);
		if (str == "ADD")
			phonebook.addNewContact();
		else if (str == "SEARCH")
			phonebook.searchContacts();
		else if (str == "EXIT")
			break;
	}
	return (0);
}
