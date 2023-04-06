/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:09 by swillis           #+#    #+#             */
/*   Updated: 2023/04/06 18:29:06 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <map>
# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <fstream>
# include <sstream>

class BitcoinExchange {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		BitcoinExchange( void );

		// Parametric Constructor
		BitcoinExchange( const std::string& db_path );

		// Copy Constructor
		BitcoinExchange( BitcoinExchange const & src );
	
		// Destructor
		~BitcoinExchange( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		BitcoinExchange &	operator=(const BitcoinExchange & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void	streamClean( std::string& str );
		float   str2f(const std::string& str);
		bool	isValidDate(const std::string& dateStr);
		void	importDB( void );
		void	inputCalc( const std::string& input );
		
	private:

        const std::string     			_db_path;
		std::map<std::string, float>    _db;
};

#endif
