/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:53:02 by swillis           #+#    #+#             */
/*   Updated: 2023/04/06 18:21:51 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int   str2i(const std::string& str) {
    
    std::istringstream iss(str);
    int i;

    iss >> i;
    return i;
}

int main(int ac, char **av) {

    if (ac != 2)
    {
        std::cout << "Error: Wrong number of argments" << std::endl;
        return 1;
    }

    std::stack<int> operands;
    std::string token;
    std::stringstream ss(av[1]);

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (operands.size() < 2) {
                std::cout << "Error" << std::endl;
                return 1;
            }
            int rhs = operands.top();
            operands.pop();
            int lhs = operands.top();
            operands.pop();
            int result;
            if (token == "+")
                result = lhs + rhs;
            else if (token == "-")
                result = lhs - rhs;
            else if (token == "*")
                result = lhs * rhs;
            else if (token == "/") {
                if (rhs == 0) {
                    std::cout << "Error: Division by zero" << std::endl;
                    return 1;
                }
                result = lhs / rhs;
            }
            operands.push(result);
        } 
        else {
            int operand;
            try {
                operand = str2i(token);
            } catch (std::invalid_argument&) {
                std::cout << "Error: Invalid operand " << token << std::endl;
                return 1;
            } catch (std::out_of_range&) {
                std::cout << "Error: Operand " << token << " out of range" << std::endl;
                return 1;
            }
            operands.push(operand);
        }
    }
    if (operands.size() != 1) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::cout << operands.top() << std::endl;
    return 0;
}
