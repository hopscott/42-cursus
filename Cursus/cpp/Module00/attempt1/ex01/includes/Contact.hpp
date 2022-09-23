/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/09/23 14:57:25 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <sstream>

class Contact {

public:

	Contact( void );
	~Contact( void );

	void		setIndex( int idx );
	void		setFirstName( std::string& str );
	void		setLastName( std::string str );
	void		setNickname( std::string str );
	void		setPhoneNumber( std::string str );
	void		setDarkestSecret( std::string str );
	int			promptDetails ( void );

	int			getIndex( void ) const;
	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getDarkestSecret( void ) const;


	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
private:

};

bool	containsNonPrintables( std::string& str );
bool	containsGraph( std::string& str );
void	streamClean( std::string& str );

#endif
