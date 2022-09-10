/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/10 22:44:00 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	
	std::cout << "Constructor called - Contact" << std::endl;
	return;
}

Contact::~Contact( void ) {
	
	std::cout << "Destructor called - Contact" << std::endl;
	return;
}

void	Contact::setIndex( int idx ) {
	
	if ((idx > 0) && (idx < 9))
		this->_index = idx;
}

void	Contact::setFirstName( std::string str ) {
	
	if (!str.empty())
		this->_firstName = str;
}

void	Contact::setLastName( std::string str ) {
	
	if (!str.empty())
		this->_lastName = str;
}

void	Contact::setNickname( std::string str ){
	
	if (!str.empty())
		this->_nickname = str;
}

void	Contact::setPhoneNumber( std::string str ){
	
	if (!str.empty())
		this->_phoneNumber = str;
}

void	Contact::setDarkestSecret( std::string str ){
	
	if (!str.empty())
		this->_darkestSecret = str;
}

int			Contact::getIndex( void ) const {

	return this->_index;
}

std::string	Contact::getFirstName( void ) const {

	return this->_firstName;
}

std::string	Contact::getLastName( void ) const {

	return this->_lastName;
}

std::string	Contact::getNickname( void ) const {

	return this->_nickname;
}

std::string	Contact::getPhoneNumber( void ) const {

	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const {

	return this->_darkestSecret;
}

void	Contact::promptDetails ( void ) {

	std::string	str;

	std::cout << "Enter First Name : ";
	std::getline (std::cin, str);
	this->setFirstName(str);
	
	std::cout << "Enter Last Name : ";
	std::getline (std::cin, str);
	this->setLastName(str);
	
	std::cout << "Enter Nickname : ";
	std::getline (std::cin, str);
	this->setNickname(str);
	
	std::cout << "Enter Phone Number : ";
	std::getline (std::cin, str);
	this->setPhoneNumber(str);
	
	std::cout << "Enter Darkest Secret : ";
	std::getline (std::cin, str);
	this->setDarkestSecret(str);
}