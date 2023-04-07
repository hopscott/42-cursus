/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:26 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 19:21:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sequence>" << std::endl;
        return 1;
    }

    std::vector<int> arr;
	for (int i = 1; i < argc; i++) {
		int num = std::stoi(argv[i]);
		arr.push_back(num);
	}

	std::cout << "Unsorted sequence: ";
	for (int x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	// Sort using std::vector
	auto start_time = std::chrono::steady_clock::now();
	merge_insertion_sort(arr, 0, arr.size() - 1);
	auto end_time = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end_time - start_time;

	std::cout << "Sorted sequence (using std::vector): ";
	for (int x : arr)
		std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "Time taken (using std::vector): " << elapsed_seconds.count() << " seconds" << std::endl;

	// Sort using std::list
	std::list<int> lst(arr.begin(), arr.end());
	start_time = std::chrono::steady_clock::now();
	lst.sort();
	end_time = std::chrono::steady_clock::now();
	elapsed_seconds = end_time - start_time;

	std::cout << "Sorted sequence (using std::list): ";
	for (int x : lst)
		std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "Time taken (using std::list): " << elapsed_seconds.count() << " seconds" << std::endl;

	return 0;

}
