/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/09/26 16:52:07 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stringstream>

int	main( int ac, char **av )
{
    std::string         filename;
    std::stringstream   ss;
    std::string         s1;
    std::string         s2;
    std::string         str;

    if (ac != 4)
        return 1;
    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    std::ifstream   ifs(filename);

    if (ifs) {
        ss << ifs.rdbuf()
        ifs.close();
    }

    while ()

    filename.append(".replace");
    std::ofstream   ofs(filename);
    
	return (0);
}
