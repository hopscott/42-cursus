/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:04 by swillis           #+#    #+#             */
/*   Updated: 2023/04/06 18:31:27 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
BitcoinExchange::BitcoinExchange( void )
: _db_path( "assets/data.csv" )
{
	return;
}

// Parametric Constructor
BitcoinExchange::BitcoinExchange( const std::string& db_path )
: _db_path( db_path )
{
	return;
}

// Copy Constructor
BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )
: _db_path( src._db_path ), _db( src._db )
{
	return;
}

// Destructor
BitcoinExchange::~BitcoinExchange( void )
{
	return;
}

// --------------- OPERATOR OVERLOADS ---------------w

// Copy Assignment Operator Overload
BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange & rhs)
{

	if (this != &rhs)
	{
		// _db( rhs._db );
	}

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

void	BitcoinExchange::streamClean( std::string& str ) {

	std::stringstream	stream;
	std::string			s;

	stream << str;
	str.clear();
	while (stream >> s)
		str.append(s + ' ');
    if (str.length() > 0) {
        str.resize(str.length() - 1);
    }
}

float   BitcoinExchange::str2f(const std::string& str) {
    
    std::istringstream iss(str);
    float f;

    iss >> f;
    return f;
}

bool	BitcoinExchange::isValidDate(const std::string& dateStr) {
    
    std::stringstream ss(dateStr);

    if (ss.good()) {

        std::string     yearStr;
        std::string     monthStr;
        std::string     dayStr;
        
        std::getline(ss, yearStr, '-');
        std::getline(ss, monthStr, '-');
        std::getline(ss, dayStr, '-');

        std::istringstream   isy(yearStr);
        std::istringstream   ism(monthStr);
        std::istringstream   isd(dayStr);

        int     year;
        int     month;
        int     day;
        
        isy >> year;
        ism >> month;
        isd >> day;

        if (year < 1 || year > 9999)
            return false;

        if (month < 1 || month > 12)
            return false;
        
        if (day < 1 || day > 31)
            return false;

        return true;
    }

    return false;
}

void	BitcoinExchange::importDB( void ) {

	std::ifstream   dbfs(_db_path.c_str());

	if (!dbfs) {
        std::cout << "Error: could not open db." << std::endl;
		return ;
	}

	std::string     str;
    std::string     date;
    std::string     value;
    float           f;

    while (std::getline(dbfs, str)) {
		
        std::stringstream   ss(str);

        if (!ss.good()) {
            std::cout << "Error: could not open stringstream." << std::endl;
            return ;
        }

        date.clear();
        value.clear();

        std::getline(ss, date, ',');
        std::getline(ss, value, ',');
		
        streamClean(date);


        if (date != "date" && !value.empty() && isValidDate(date)) {
            
            streamClean(value);

            f = str2f(value);
            _db[date] = f;
        
        }

    }

    dbfs.close();

}

void	BitcoinExchange::inputCalc( const std::string& input ) {

	std::ifstream   ifs(input.c_str());

	if (!ifs) {
        std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	std::string     str;
    std::string     date;
    std::string     value;
    float           f;

    while (std::getline(ifs, str)) {
        
        std::stringstream   ss(str);
        
        if (!ss.good()) {
            std::cout << "Error: could not open stringstream." << std::endl;
            return ;
        }
        
        date.clear();
        value.clear();

        std::getline(ss, date, '|');
        std::getline(ss, value, '|');
        
        streamClean(date);

        if (date != "date" && !value.empty() && isValidDate(date)) {
            
            streamClean(value);
            float v = str2f(value);

            try {

                f = _db.at(date);
            }
            catch (const std::out_of_range& e) {

                std::map<std::string, float>::iterator  it = _db.lower_bound(date);
                
                if (it-- == _db.end()) {
                    
                    std::cout << "Error: no bitcoin price available for " << date << std::endl;
                    continue;
                }

                f = _db[it->first];
            } 
            

            if ( v * f < 0.0 ) {

                std::cout << "Error: not a positive number." << std::endl;
                
            } 
            else if ( v * f > static_cast<float>(std::numeric_limits<int>::max()) ) {

                std::cout << "Error: too large a number." << std::endl;

            } 
            else {
                
                std::cout << date << " => " << v << " = " << v * f << std::endl;
            }

        }
        else if (date != "date") {
            
            std::cout << "Error: bad input => " << str << std::endl;
        }

    }

    ifs.close();
}
