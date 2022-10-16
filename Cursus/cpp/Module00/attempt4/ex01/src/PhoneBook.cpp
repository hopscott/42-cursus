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
	_overwriteIdx = 0;
	return;
}

PhoneBook::~PhoneBook( void ) {

	std::cout << "Destructor called - PhoneBook" << std::endl;
	return;
}

int	PhoneBook::_setContact( int idx ) {

	int	err;

	err = _contacts[idx].promptDetails();
	if (err)
		return 1;
	_contacts[idx].setIndex(idx);
	return 0;
}

Contact&	PhoneBook::_getContact( int idx ) {

	Contact&	contact = _contacts[idx];

	return contact;
}

void	PhoneBook::addNewContact ( void ) {

	if(_setContact(_overwriteIdx))
		return;
	_overwriteIdx++;
	if (_overwriteIdx > 7)
		_overwriteIdx = 0;
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

	idx = -1;
	for (int i=0; i < 3; i++) {
		std::cout << "Enter index to diplay: ";
		std::getline (std::cin, str);
		if (!containsGraph(str) || containsNonPrintables(str)) {
			std::cout << "Invalid input - Please try a valid number [1-8]..." << std::endl;
			continue;
		}
		streamClean(str);
		if (!isInt(str)) {
			std::cout << "Invalid input - Please try a valid number [1-8] without spaces or letters..." << std::endl;
			continue;
		}
		idx = std::atoi(str.c_str());
		if ((idx > 0) && (idx < 9))
			break;
		std::cout << "Invalid input - Number lies outside phonebook range [1-8]..." << std::endl;
		idx = -1;
	}

	if (idx != -1) {

		idx -= 1;
		std::cout << std::endl;
		std::cout << "First Name: " << _getContact(idx).getFirstName() << std::endl;
		std::cout << "Last Name: " << _getContact(idx).getLastName() << std::endl;
		std::cout << "Nickname: " << _getContact(idx).getNickname() << std::endl;
		std::cout << "Phone Number: " << _getContact(idx).getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _getContact(idx).getDarkestSecret() << std::endl;
		std::cout << std::endl;
	}
}
