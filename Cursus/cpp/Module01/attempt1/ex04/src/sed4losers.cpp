/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed4losers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/18 18:24:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed4losers.hpp"

int	sed4losers( std::string& filename, std::string& s1, std::string& s2 )
{
    std::stringstream   ss;
    std::string         str;
    std::string         substr;
    std::string         nstr;
    std::size_t         found;
    std::size_t         prev_found;

    // Input file
    std::ifstream   ifs(filename.c_str());
    if (!ifs)
       return 1;

    // Read buffer into stringstream then convert to string
    ss << ifs.rdbuf();
    ifs.close();
    str = ss.str();

    // Algo for substr find and replace
    prev_found = 0;
    found = str.find(s1, prev_found);
    while (found != std::string::npos) {

        substr = str.substr(prev_found, (found - prev_found));
        nstr.append(substr);
        nstr.append(s2);
        prev_found = found + s1.length();
        found = str.find(s1, prev_found);
    }
    substr = str.substr(prev_found, str.length());
    nstr.append(substr);

    // Output file
    filename.append(".replace");
    std::ofstream   ofs(filename.c_str());
    if (!ofs)
        return 2;

    // Replaced string into output file
    ofs << nstr;
    ofs.close();
    
    return 0;
}
