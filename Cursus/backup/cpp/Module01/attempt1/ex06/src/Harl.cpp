/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 00:51:48 by swillis          ###   ########.fr       */
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
    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"  << std::endl << std::endl;
}

void	Harl::info( void ) {
    
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"  << std::endl << std::endl;
}

void	Harl::warning( void ) {
    
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."  << std::endl << std::endl;
}

void	Harl::error( void ) {
    
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int  Harl::findPmfIndex( std::string level ) {

    for (int i=0; i<TOTAL; i++) {

        if (level == _lvl[i])
            return i;
    }
    return (-1);
}

void	Harl::complain( std::string level ) {

    int lvl;

    lvl = findPmfIndex(level);
    switch (lvl) {
        case DEBUG:
            (this->*_pmf[INFO])();
            (this->*_pmf[WARNING])();
            (this->*_pmf[ERROR])();
            (this->*_pmf[DEBUG])();
            break;
        case INFO:
            (this->*_pmf[INFO])();
            (this->*_pmf[WARNING])();
            (this->*_pmf[ERROR])();
            break;
        case WARNING:
            (this->*_pmf[WARNING])();
            (this->*_pmf[ERROR])();
            break;
        case ERROR:
            (this->*_pmf[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
