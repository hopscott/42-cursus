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
	
	int	err;

	err = _contacts[idx].promptDetails();
	if (err)
		return;
	_contacts[idx].setIndex(idx);
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

bool	isInt( std::string& str ) {

	if ((int)str.length() > 10)
		return (false);

	for (int i = 0; i < (int)str.length(); i++) {
		
		if (std::isdigit(str[i]))
			return (true);
	}
	return (false);
}

void	PhoneBook::searchContacts ( void ) {

	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	str;
	int			idx;

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

	for (int i=0; i < 3; i++) {
		std::cout << "Enter index to diplay: ";
		std::getline (std::cin, str);
		if (!containsGraph(str) || containsNonPrintables(str)) {
			std::cout << "Invalid input - Please try a valid number [0-8]..." << std::endl;
			continue;
		}
		streamClean(str);
		if (!isInt(str)) {
			std::cout << "Invalid input - Please try a valid number [0-8] without spaces or letters..." << std::endl;
			continue;
		}
		idx = std::atoi(str.c_str());
		if ((idx < 1) || (idx > 8)) {
			std::cout << "Invalid input - Number lies outside phonebook range [0-8]..." << std::endl;
			continue;
		}
	}
}
