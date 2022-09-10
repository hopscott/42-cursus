/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/10 21:59:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
