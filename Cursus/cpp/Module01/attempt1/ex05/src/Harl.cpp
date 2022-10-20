/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 01:31:52 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const char*             Harl::_lvl[TOTAL] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const Harl::PtrMemFunc  Harl::_pmf[TOTAL] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl( void ) {

	return;
}

Harl::~Harl( void ) {
    
    return;
}

void	Harl::debug( void ) {

    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info( void ) {
    
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void ) {
    
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void ) {
    
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain( std::string level ) {

    for (int i=0; i<TOTAL; i++) {

        if (level == _lvl[i]) {
            
            (this->*_pmf[i])();
            return;
        }
    }
    
    std::cout << "Try DEBUG or INFO or WARNING or ERROR instead" << std::endl << std::endl;
}
