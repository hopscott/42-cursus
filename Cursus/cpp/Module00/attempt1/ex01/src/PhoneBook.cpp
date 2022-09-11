/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/11 20:52:07 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	
	std::cout << "Constructor called - PhoneBook" << std::endl;
	for (int i=1; i<9; i++) {
		this->_contacts[i] = NULL;
	}
	return;
}

PhoneBook::~PhoneBook( void ) {
	
	std::cout << "Destructor called - PhoneBook" << std::endl;
	for (int i=1; i<9; i++) {
		if (this->getContact(i))
			delete this->_contacts[i];
	}
	return;
}

Contact	*PhoneBook::getContact( int idx ) const {
	
	return this->_contacts[idx];
}

void	PhoneBook::setContact( int idx, Contact *contact ) {
	
	this->_contacts[idx] = contact;
}

void	PhoneBook::addNewContact ( void ) {

	Contact		*contact = new Contact();
	int			idx;
	
	contact->promptDetails();
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
	this->setContact(idx, contact);
}
