/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:09 by swillis           #+#    #+#             */
/*   Updated: 2023/03/30 19:22:19 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>

class BitcoinExchange {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		BitcoinExchange( void );

		// Parametric Constructor
		BitcoinExchange( const std::string path );

		// Copy Constructor
		BitcoinExchange( BitcoinExchange const & src );
	
		// Destructor
		~BitcoinExchange( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		BitcoinExchange &	operator=(const BitcoinExchange & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		
	private:

        std::string     _db_path;
};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, BitcoinExchange const & rhs );

#endif
