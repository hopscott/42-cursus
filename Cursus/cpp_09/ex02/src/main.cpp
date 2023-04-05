/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:49:26 by swillis           #+#    #+#             */
/*   Updated: 2023/04/06 00:16:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <chrono>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void insertion_sort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge_insertion_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        if (mid - left + 1 <= 32)
            insertion_sort(arr, left, mid);
        else
            merge_insertion_sort(arr, left, mid);

        if (right - mid <= 32)
            insertion_sort(arr, mid + 1, right);
        else
            merge_insertion_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

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
