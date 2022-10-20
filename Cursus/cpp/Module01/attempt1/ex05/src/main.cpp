/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 00:52:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int ac, char **av )
{
    Harl        harl;
    std::string str;

    if (ac != 2) {
        
        std::cout << "Needs only one argument such as: DEBUG or INFO or WARNING or ERROR" << std::endl << std::endl;
        return 1;
    }

    str = av[1];
    for (std::string::size_type i=0; i<str.length(); ++i)
        if (std::isprint(str[i]))
            str[i] = std::toupper(str[i]);
    
    harl.complain(str);
    
    return 0;
}
