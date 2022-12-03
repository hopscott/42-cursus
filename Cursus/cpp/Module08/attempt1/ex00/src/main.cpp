/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/03 19:06:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main( void )
{
    std::deque<int>     deq;
    std::vector<int>    vec;
    std::list<int>      lst;
    std::list<float>    flst;

    for (int i=1; i<=3; ++i)
    {
        deq.push_back(i);
        vec.push_back(i);
        lst.push_back(i);
        flst.push_back(static_cast<float>(i));
    }

    std::cout << *easyfind(deq, 1) << std::endl;
    std::cout << *easyfind(vec, 2) << std::endl;
    std::cout << *easyfind(lst, 3) << std::endl;

    try
    {
        std::cout << *easyfind(lst, -1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(lst, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(flst, 3) << std::endl;
        std::cout << *easyfind(flst, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
