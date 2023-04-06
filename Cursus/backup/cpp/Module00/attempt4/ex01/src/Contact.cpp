/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/26 12:58:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	
	std::cout << "Constructor called - Contact" << std::endl;
	this->setIndex(-1);
	return;
}

Contact::~Contact( void ) {
	
	std::cout << "Destructor called - Contact" << std::endl;
	return;
}

/* **************** */
/* 		SETTERS		*/
/* **************** */

void	Contact::setIndex( int idx ) {
	
	if ((idx >= -1) && (idx < 9))
		this->_index = idx;
}

void	Contact::setFirstName( std::string& str ) {
	
	_firstName = str;
}

void	Contact::setLastName( std::string str ) {
	
	_lastName = str;
}

void	Contact::setNickname( std::string str ) {
	
	_nickname = str;
}

void	Contact::setPhoneNumber( std::string str ) {
	
	_phoneNumber = str;
}

void	Contact::setDarkestSecret( std::string str ) {
	
	_darkestSecret = str;
}

/* **************** */
/* 		GETTERS		*/
/* **************** */

int			Contact::getIndex( void ) const {

	return _index;
}

std::string	Contact::getFirstName( void ) const {

	return _firstName;
}

std::string	Contact::getLastName( void ) const {

	return _lastName;
}

std::string	Contact::getNickname( void ) const {

	return _nickname;
}

std::string	Contact::getPhoneNumber( void ) const {

	return _phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const {

	return _darkestSecret;
}

/* **************** */
/* 		OTHERS		*/
/* **************** */

bool	containsNonPrintables( std::string& str ) {

	for (int i=0; i<(int)str.length(); i++) {
		
		if (!std::isprint(str[i]))
			return (true);
	}
	return (false);
}

bool	containsGraph( std::string& str ) {

	for (int i = 0; i < (int)str.length(); i++) {
		
		if (std::isgraph(str[i]))
			return (true);
	}
	return (false);
}

void	streamClean( std::string& str ) {

	std::stringstream	stream;
	std::string			s;

	stream << str;
	str.clear();
	while (stream >> s)
		str.append(s + ' ');
	str.resize(str.length() - 1);
}

int	Contact::promptDetails ( void ) {

	int			attempts;
	std::string	details[5];

	attempts = 1;
	for (int i=0; i<5; i++) {
		switch (i) {
			case 0:	
				std::cout << "Enter First Name : ";
				break;
			case 1:	
				std::cout << "Enter Last Name : ";
				break;
			case 2:	
				std::cout << "Enter Nickname : ";
				break;
			case 3:	
				std::cout << "Enter Phone Number : ";
				break;
			case 4:	
				std::cout << "Enter Darkest Secret : ";
				break;
		}
		std::getline (std::cin, details[i]);
		if (!containsGraph(details[i]) || containsNonPrintables(details[i])) {
			std::cout << std::endl << "Invalid entry - Please try again..." << std::endl << std::endl;
			i--;
			attempts++;
			if (attempts > 3) {
				std::cout << "Too many failed attempts - Leaving contact add..." << std::endl << std::endl;
				return 1;
			}
		}
		else {
			attempts = 1;
			streamClean(details[i]);
		}
	}
	
	for (int i=0; i<5; i++) {
		switch (i) {
			case 0:	
				setFirstName(details[i]);
				break;
			case 1:	
				setLastName(details[i]);
				break;
			case 2:	
				setNickname(details[i]);
				break;
			case 3:	
				setPhoneNumber(details[i]);
				break;
			case 4:	
				setDarkestSecret(details[i]);
				break;
		}
	}
	return 0;
}
