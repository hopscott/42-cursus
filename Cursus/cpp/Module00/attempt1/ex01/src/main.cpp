/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/09/10 22:06:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "main.hpp"

void	editContact ( Contact& contact ) {

	std::string	str;

	std::cout << "Enter First Name : ";
	std::getline (std::cin, str);
	contact.setFirstName(str);
	
	std::cout << "Enter Last Name : ";
	std::getline (std::cin, str);
	contact.setLastName(str);
	
	std::cout << "Enter Nickname : ";
	std::getline (std::cin, str);
	contact.setNickname(str);
	
	std::cout << "Enter Phone Number : ";
	std::getline (std::cin, str);
	contact.setPhoneNumber(str);
	
	std::cout << "Enter Darkest Secret : ";
	std::getline (std::cin, str);
	contact.setDarkestSecret(str);
}

void	addNewContact ( PhoneBook& phonebook ) {

	Contact		contact;
	
	(void)phonebook;
	editContact(contact);
	for (int idx=1; idx<9; ++idx) {
		std::cout << idx;
		contact.setIndex( idx );
	}
	std::cout << "Finished editing" << std::endl;

}

int	main( void )
{
	std::string	str;
	PhoneBook	phonebook;

	while (std::cin)
	{
		std::cout << "Enter a command [ADD, SEARCH or EXIT]: " << std::endl;
		std::getline (std::cin, str);
		if (str == "ADD")
			addNewContact(phonebook);
		if (str == "EXIT")
			break ;
	}
	return (0);
}
