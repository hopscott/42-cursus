/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:26 by swillis           #+#    #+#             */
/*   Updated: 2023/04/09 00:21:59 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cmath>

int main(int ac, char **av) {
    
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    PmergeMe					pmm;
    std::vector<unsigned int>	vec;
    std::list<unsigned int>		lst;

    std::clock_t	start_clock;
	std::clock_t	end_clock;
    double			elapsed_seconds;
    double			elapsed_microseconds;


	std::cout << "Before:  ";
	for (int i=0; i<5; ++i) {

		if ((i > 3) && (ac - 1 > 5)) {

			std::cout << "[...] ";
		}
		else if (i < ac - 1) {
			
			std::cout << av[i+1] << " ";
		}
	}
	std::cout << std::endl;

	// VECTOR

    start_clock = std::clock();

	for (int i=1; i<ac; i++) {
		
		int n = pmm.str2i(av[i]);
		vec.push_back(n);
	}

    pmm.vecMergeInsertionSort(vec);

    end_clock = std::clock();
    elapsed_seconds = static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC;
	elapsed_microseconds = elapsed_seconds * std::pow(10, 6);

	std::cout << "After:   ";
	for (int i=0; i<5; ++i) {

		if ((i > 3) && (ac - 1 > 5)) {

			std::cout << "[...] ";
		}
		else if (i < ac - 1) {
			
			std::cout << vec[i] << " ";
		}
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of ";
	std::cout << std::setw(4) << vec.size();
	std::cout << " elements with std::vector : ";
	std::cout << std::setw(8) << std::fixed << std::setprecision(5) << elapsed_seconds;
	std::cout << " us" << std::endl;

	// LIST

    start_clock = std::clock();
	
	for (int i=1; i<ac; i++) {
		
		int n = pmm.str2i(av[i]);
		lst.push_back(n);
	}

    pmm.lstMergeInsertionSort(lst);

    end_clock = std::clock();
    elapsed_seconds = static_cast<double>(end_clock - start_clock) / CLOCKS_PER_SEC;
	elapsed_microseconds = elapsed_seconds * std::pow(10, 6);

	std::cout << "Time to process a range of ";
	std::cout << std::setw(4) << lst.size();
	std::cout << " elements with std::list :   ";
	std::cout << std::setw(8) << std::fixed << std::setprecision(5) << elapsed_seconds;
	std::cout << " us" << std::endl;

	return 0;

}
