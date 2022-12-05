/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/06 00:04:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    std::cout << "=== SPAN ===" << std::endl;
    
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << RED "--- addNumber above limit ---" << std::endl;
        
        sp.addNumber(11);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << RESET "=== SPAN2 ===" << std::endl;

    Span sp2 = Span(10000);
	std::vector<int> 	v;

    try
    {

        std::cout << RESET YELLOW "--- addNumber ---" << std::endl;

        sp2.addNumber(6);
        sp2.addNumber(3);
        sp2.addNumber(17);
        sp2.addNumber(9);
        sp2.addNumber(11);

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        
        std::cout << RESET GREEN "--- addIterNumbers with vector iterators ---" << std::endl;
        
        int tab[3] = {23, 366, 2};
        sp2.addIterNumbers(tab, &tab[3]);

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << RESET << std::endl;
    
        std::cout << RESET BLUE "--- addIterNumbers with tab ---" << std::endl;

        v.push_back(0);
        v.push_back(100);
        v.push_back(100);
        v.push_back(200);
        v.push_back(10000);
        sp2.addIterNumbers(v.begin(), v.end());
        
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
