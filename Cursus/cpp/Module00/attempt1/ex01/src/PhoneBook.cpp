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

Contact	*PhoneBook::getContact( int idx ) {
	
	Contact	*contact;
	
	contact = &this->_contacts[idx];
	if (contact->getIndex() == -1)
		return (NULL);
	return contact;
}

void	PhoneBook::setContact( int idx ) {
	
	Contact	*contact;

	contact = getContact(idx);
	contact->promptDetails();
}

void	PhoneBook::addNewContact ( void ) {

	int			idx;
	
	idx = -1;
	for (int i=1; i<9; i++) {
		if (!this->getContact(i))
		{
			idx = i;
			break;
		}
	}
	if (idx == -1)
		idx = 1;
	this->setContact(idx);
}

void	PhoneBook::searchContacts ( void ) {

	Contact		*contact;
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

	for (int i=1; i<9; i++) {

		contact = this->getContact(i);
		firstname = contact->getFirstName();
		lastname = contact->getLastName();
		nickname = contact->getNickname();
		
		if (firstname.length() > 10) {
			firstname.resize(9);
			firstname.resize(10, '.');
		}
		
		if (lastname.length() > 10) {
			lastname.resize(9);
			lastname.resize(10, '.');
		}
		
		if (nickname.length() > 10) {
			nickname.resize(9);
			nickname.resize(10, '.');
		}
		
		std::cout << std::setw(10) << i << "|" <<
					 std::setw(10) << firstname << "|" <<
					 std::setw(10) << lastname << "|" <<
					 std::setw(10) << nickname << std::endl;
	}
}
