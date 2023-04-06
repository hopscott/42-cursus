/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:34:34 by swillis           #+#    #+#             */
/*   Updated: 2023/04/05 23:53:13 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>

void	streamClean( std::string& str ) {

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

float   str2f(const std::string& str) {
    
    std::istringstream iss(str);
    float f;

    iss >> f;
    return f;
}

bool isValidDate(const std::string& dateStr) {
    
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

int main(int ac, char **av) {
    
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
	std::string     db = "assets/data.csv";
	std::ifstream   dbfs(db.c_str());

	if (!dbfs) {
        std::cout << "Error: could not open db." << std::endl;
		return 1;
	}

	std::string     str;
    std::map<std::string, float>    dv_map;

    std::string         date;
    std::string         value;
    float               f;

    while (std::getline(dbfs, str)) {
		
        std::stringstream   ss(str);

        if (!ss.good()) {
            std::cout << "Error: could not open stringstream." << std::endl;
            return 1;
        }

        date.clear();
        value.clear();

        std::getline(ss, date, ',');
        std::getline(ss, value, ',');
		
        streamClean(date);


        if (date != "date" && !value.empty() && isValidDate(date)) {
            
            streamClean(value);

            f = str2f(value);
            dv_map[date] = f;
        
        }

    }

    dbfs.close();



	std::string     input = av[1];
	std::ifstream   ifs(input.c_str());

	if (!ifs) {
        std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

    while (std::getline(ifs, str)) {
        
        std::stringstream   ss(str);
        
        if (!ss.good()) {
            std::cout << "Error: could not open stringstream." << std::endl;
            return 1;
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

                f = dv_map.at(date);
            }
            catch (const std::out_of_range& e) {

                std::map<std::string, float>::iterator  it = dv_map.lower_bound(date);
                
                if (it-- == dv_map.end()) {
                    
                    std::cout << "Error: no bitcoin price available for " << date << std::endl;
                    continue;
                }

                f = dv_map[it->first];
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

    return 0;
}
