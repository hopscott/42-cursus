/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/17 15:58:09 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int	main( int ac, char **av )
{
    std::string         filename;
    std::stringstream   ss;
    std::string         s1;
    std::string         s2;
    std::string         str;
    std::string         substr;
    std::string         nstr;

    if (ac != 4)
        return 1;
    if (!av[1] || !av[2] || !av[3])
        return 2;
    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    std::ifstream   ifs(filename.c_str());
    if (!ifs) 
        return 3;

    ss << ifs.rdbuf();
    ifs.close();

    str = ss.str();

    std::size_t found = str.find(s1);
    std::cout << "FOUND->" << found;

    while (found != std::string::npos) {

        substr = str.substr(0, found);
        nstr.append(substr);
        nstr.append(s2);
        found = str.find(s1);
    }

    substr = str.substr(found, str.length());
    nstr.append(substr);

    filename.append(".replace");
    std::ofstream   ofs(filename.c_str());
    if (!ofs)
        return 4;
        
    ofs << nstr;
    ofs.close();
    
    return 0;
}
