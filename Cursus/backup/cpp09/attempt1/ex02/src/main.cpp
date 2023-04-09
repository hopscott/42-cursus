/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:26 by swillis           #+#    #+#             */
/*   Updated: 2023/04/09 02:24:33 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <set>
#include <ctime>
#include <cmath>

// https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/

int main(int ac, char **av) {
    
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

	std::set<std::string> strset;

	for (int i=1; i<ac; ++i) {

        std::string str = av[i];
		
		// -ve check
		if (str.find('-') != std::string::npos) {
			
			std::cout << "Error" << std::endl;
			return 1;
		}

		// +ve check
		std::size_t pos = str.find('+');
		if ((pos > 1 && pos != std::string::npos) || str.find('+', pos + 1) != std::string::npos) {
			
			std::cout << "Error" << std::endl;
			return 1;
		}

		// unsigned int check
		if (str.length() > std::numeric_limits<unsigned int>::digits10 + 1) {
			
			std::cout << "Error" << std::endl;
			return 1;
		}
		else if (str.length() == 10) {
			
			for (int i=0; i<10; i++) {
				
				if (str[i] > "4294967295"[i]) {
					
					std::cout << "Error" << std::endl;
					return 1;
				}
				else if (str[i] < "4294967295"[i]) {
					break;
				}
			}
		}

		// duplicate check
        if (strset.count(str) > 0) {
			std::cout << "Error" << std::endl;
			return 1;
        } 
		else {
            strset.insert(str);
        }
    }

    PmergeMe	pmm;

	// clock_t start;
	// clock_t end;
	timespec	start;
	timespec	end;
	double		duration;

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

    // start = std::clock();
	clock_gettime(CLOCK_MONOTONIC, &start);

    std::vector<unsigned int>	vec;

	for (int i=1; i<ac; i++) {
		
		int n = pmm.str2i(av[i]);
		vec.push_back(n);
	}

    pmm.vecMergeInsertionSort(vec);

	clock_gettime(CLOCK_MONOTONIC, &end);
	duration = (end.tv_sec - start.tv_sec) * std::pow(10, 9);
	duration += (end.tv_nsec - start.tv_nsec);
	duration /= std::pow(10, 3);
	
    // end = std::clock();
    // duration = (static_cast<double>(end - start) * std::pow(10, 6)) / CLOCKS_PER_SEC;

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
	std::cout << std::setw(8) << std::fixed << std::setprecision(5) << duration;
	std::cout << " us" << std::endl;

	// LIST
	
    // start = std::clock();
	clock_gettime(CLOCK_MONOTONIC, &start);

    std::list<unsigned int>		lst;

	for (int i=1; i<ac; i++) {
		
		int n = pmm.str2i(av[i]);
		lst.push_back(n);
	}

    pmm.lstMergeInsertionSort(lst);

	clock_gettime(CLOCK_MONOTONIC, &end);
	duration = (end.tv_sec - start.tv_sec) * std::pow(10, 9);
	duration += (end.tv_nsec - start.tv_nsec);
	duration /= std::pow(10, 3);

    // end = std::clock();
    // duration = (static_cast<double>(end - start) * std::pow(10, 6)) / CLOCKS_PER_SEC;
	
	// std::cout << "After:   ";
	// for (std::list<unsigned int>::iterator it=lst.begin(); it!=lst.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	std::cout << "Time to process a range of ";
	std::cout << std::setw(4) << lst.size();
	std::cout << " elements with std::list :   ";
	std::cout << std::setw(8) << std::fixed << std::setprecision(5) << duration;
	std::cout << " us" << std::endl;

	return 0;

}
