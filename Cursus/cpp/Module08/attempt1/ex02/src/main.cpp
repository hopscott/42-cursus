/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/05 18:21:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main( void )
{
    MutantStack<int>    mstack;
    std::list<int>      lst;

    std::cout << YELLOW "=== MUTANT STACK ===" << std::endl << std::endl;

    std::cout << YELLOW "--- mutantstack ---" << std::endl << std::endl;

    mstack.push(5);

    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    std::cout << std::endl;
    
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    std::cout << std::endl;
    
    mstack.pop();

    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    std::cout << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator  it = mstack.begin();
    MutantStack<int>::iterator  ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << ">> " << *it << std::endl;
        ++it;
    }

    std::stack<int>  s(mstack);

    std::cout << std::endl << RESET RED "--- copy into stack ---" << std::endl << std::endl;

    // it = s.begin();
    // ite = s.end();

    std::cout << "top: " << s.top() << std::endl;
    std::cout << "size: " << s.size() << std::endl;

    std::cout  << std::endl << RESET BLUE "=== LIST ===" << std::endl << std::endl;


    lst.push_back(5);

    std::cout << "top: " << lst.back() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;
    
    std::cout << std::endl;

    lst.push_back(17);

    std::cout << "top: " << lst.back() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;

    std::cout << std::endl;
    
    lst.pop_back();

    std::cout << "top: " << lst.back() << std::endl;
    std::cout << "size: " << lst.size() << std::endl;

    std::cout << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::const_iterator      lit = lst.begin();
    std::list<int>::const_iterator      lite = lst.end();

    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << ">> " << *lit << std::endl;
        ++lit;
    }

    return 0;
}
