/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/21 02:01:34 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main( int ac, char **av )
{
    std::string input;

    // Check args
    if (ac != 2) {
        
        std::cout << "[ ERROR ]" << std::endl << "Wrong arguments => Need filename, string to find, and string for replacing" << std::endl << std::endl;
        return 1;
    }

    // Set inputs
    input = av[1];


    return 0;
}
