/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/12 18:18:55by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	
	std::cout << "Constructor called - PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void ) {
	
	std::cout << "Destructor called - PhoneBook" << std::endl;
	return;
}

void	PhoneBook::setContact( int idx ) {
	
	_contacts[idx].setIndex(idx);
	_contacts[idx].promptDetails();
}

void	PhoneBook::addNewContact ( void ) {

	int			idx;
	
	idx = -1;
	for (int i=0; i<8; i++) {
		if (_contacts[i].getIndex() == -1)
		{
			idx = i;
			break;
		}
	}
	if (idx == -1)
		idx = 0;
	setContact(idx);
}

void	PhoneBook::searchContacts ( void ) {

	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	std::cout << std::endl <<
				 std::setw(10) << "Index" << "|" <<
				 std::setw(10) << "First Name" << "|" <<
				 std::setw(10) << "Last Name" << "|" <<
				 std::setw(10) << "Nickname" << std::endl;

	std::cout << std::setw(10) << "__________" << "|" <<
				 std::setw(10) << "__________" << "|" <<
				 std::setw(10) << "__________" << "|" <<
				 std::setw(10) << "__________" << std::endl;

	for (int idx=0; idx<8; idx++) {

		firstname = "";
		lastname = "";
		nickname = "";
		Contact& contact = _contacts[idx];
		if (contact.getIndex() != -1) {

			firstname = contact.getFirstName();
			lastname = contact.getLastName();
			nickname = contact.getNickname();
		
			if (firstname.length() > 10) {
				firstname.resize(10);
				firstname[9] = '.';
			}
		
			if (lastname.length() > 10) {
				lastname.resize(10);
				lastname[9] = '.';
			}
		
			if (nickname.length() > 10) {
				nickname.resize(10);
				nickname[9] = '.';
			}
		}
		
		std::cout << std::setw(10) << idx+1 << "|" <<
					 std::setw(10) << firstname << "|" <<
					 std::setw(10) << lastname << "|" <<
					 std::setw(10) << nickname << std::endl;
	}
}
