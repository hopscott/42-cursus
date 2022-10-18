/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/18 18:24:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed4losers.hpp"

int	main( int ac, char **av )
{
    std::string filename;
    std::string s1;
    std::string s2;

    // Check args
    if (ac != 4)
        return 1;
    if (!av[1] || !av[2] || !av[3])
        return 2;

    // Set inputs
    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    // Apply sed4losers function
    sed4losers(filename, s1, s2);

    return 0;
}
