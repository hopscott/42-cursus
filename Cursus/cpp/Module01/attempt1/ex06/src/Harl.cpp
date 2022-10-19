/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/18 19:00:53 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {

	return;
}

Harl::~Harl( void ) {
    
    return;
}

void	Harl::debug( void ) {
    std::cout << "DEBUG = I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
    
    std::cout << "INFO = I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
    
    std::cout << "WARNING = I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
    
    std::cout << "ERROR = This is unacceptable! I want to speak to the manager now." << std::endl;
}
	
void	Harl::complain( std::string level ) {
    
    typedef void (Harl::*PtrMemFunc) (void);
    
    PtrMemFunc pmf[4];
    
    pmf[0] = &Harl::debug;
    pmf[1] = &Harl::info;
    pmf[2] = &Harl::warning;
    pmf[3] = &Harl::error;
    
    while (level >= 0) {
        
        switch (level)
        {
            case std::string("DEBUG"):
                break;
            case "INFO":
                break;
            case "WARNING":
                break;
            case "ERROR":
                break;
            
            default:
                break;
        }
        *pmf[level];
        level--;
    }
}
