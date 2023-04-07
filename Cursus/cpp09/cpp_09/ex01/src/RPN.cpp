/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:04 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 18:33:21 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
RPN::RPN( void )
{
	return;
}

// Parametric Constructor
RPN::RPN( const std::string& str )
: _str( str )
{
	return;
}

// Copy Constructor
RPN::RPN( RPN const & src )
: _str( src._str ), _result( src._result )
{
	return;
}

// Destructor
RPN::~RPN( void )
{
	return;
}

// --------------- OPERATOR OVERLOADS ---------------w

// Copy Assignment Operator Overload
RPN &	RPN::operator=(const RPN & rhs)
{

	if (this != &rhs)
	{
		_str = rhs._str;
		_result = rhs._result;
	}

	return *this;
}

// --------------- FUNCTIONS ---------------

// Member functions

int		RPN::str2i(const std::string& str) {
    
    std::istringstream iss(str);
    int i;

    iss >> i;
    return i;
}

void	RPN::calculate(const std::string& str) {

	_str = str;

    std::stack<int> 	ops;
    std::string 		token;
    std::stringstream 	ss(_str);

    while (ss >> token) {
		
        if (token == "+" || token == "-" || token == "*" || token == "/") {
			
            if (ops.size() < 2) {
                std::cout << "Error" << std::endl;
                return ;
            }
			
            int rhs = ops.top();
            ops.pop();
			
            int lhs = ops.top();
            ops.pop();
			
            int _result;

            if (token == "+") {
				
                _result = lhs + rhs;
			}
            else if (token == "-") {
				
                _result = lhs - rhs;
			}
            else if (token == "*") {
				
                _result = lhs * rhs;
			}
            else if (token == "/") {
				
                if (rhs == 0) {
					
                    std::cout << "Error" << std::endl;
                    return ;
                }
				
                _result = lhs / rhs;
            }
			
            ops.push(_result);
		
        } 
        else if ( std::isdigit(token[0]) ) {

            int op;
			
			op = RPN::str2i(token);
            ops.push(op);
			
        }
		else {

			std::cout << "Error" << std::endl;
			return ;

		}
    }

    if (ops.size() != 1) {
		
        std::cout << "Error" << std::endl;
        return ;
    }
	
    std::cout << ops.top() << std::endl;
}
