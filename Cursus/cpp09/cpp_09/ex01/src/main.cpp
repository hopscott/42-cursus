/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:53:02 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 18:35:03 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN     calculator;
    
    calculator.calculate(av[1]);

    return 0;
}
