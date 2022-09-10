/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/10 22:44:06 by swillis          ###   ########.fr       */
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

Contact	*PhoneBook::getContact( int idx ) const {
	
	return this->_contacts[idx];
}

// void	PhoneBook::setContact( int idx, Contact& contact ) const {
	
// }

void	PhoneBook::addNewContact ( void ) {

	Contact		contact;
	int			idx;
	
	contact.promptDetails();
	idx = -1;
	for (int i=1; i<9; ++i) {
		if (!this->getContact(i))
			idx = i;
	}
	if (idx == -1)
		idx = 1;
	// this->setContact(idx, contact);
	
}
