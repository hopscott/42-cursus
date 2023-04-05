/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2023/01/10 18:07:58 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Vector.hpp"

#include "RandomAccessIterator.hpp"

#include <iostream>
#include <cassert>

int main(int, char**)
{
	ft::Vector<int> v(10);
	
	v.assign(5, 1);

	// std::cout << v[0] << std::endl;
	// std::cout << v[1] << std::endl;
	// std::cout << v[5] << std::endl;

    // // Test basic functionality
    ft::RandomAccessIterator<int> it = v.begin();
	
	while (it != v.end())
	{
		std::cout << &it << " -> " << *it << std::endl;
		it++;
	}

	
	// // Test 1: Initial size
	
	// std::cout << &v.begin() << std::endl;
	// std::cout << &v.end() << std::endl;
	// std::cout << v.size() << std::endl;
    // assert(v.size() == 0);

    // // Test 2: push_back
    // v.push_back(1);
    // assert(v.size() == 1);
    // assert(v[0] == 1);

    // // Test 3: pop_back
    // v.pop_back();
    // assert(v.size() == 0);

    // // Test 4: clear
    // v.push_back(2);
    // v.push_back(3);
    // v.clear();
    // assert(v.size() == 0);

    // // Test 5: insert
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.insert(v.begin(), 4);
    // assert(v.size() == 4);
    // assert(v[0] == 1);
    // assert(v[1] == 4);
    // assert(v[2] == 2);
    // assert(v[3] == 3);

    // // Test 6: erase
    // v.erase(v.begin());
    // assert(v.size() == 3);
    // assert(v[0] == 1);
    // assert(v[1] == 2);
    // assert(v[2] == 3);

    // // Test 7: empty
    // assert(!v.empty());
    // v.clear();
    // assert(v.empty());

    // std::cout << "All tests passed!" << std::endl;

	return 0;
}
