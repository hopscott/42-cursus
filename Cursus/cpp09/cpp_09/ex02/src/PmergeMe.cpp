/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:04 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 20:06:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
PmergeMe::PmergeMe( void )
{
	return;
}

// Parametric Constructor
PmergeMe::PmergeMe( const std::string& str )
: _str( str )
{
	return;
}

// Copy Constructor
PmergeMe::PmergeMe( PmergeMe const & src )
: _str( src._str ), _result( src._result )
{
	return;
}

// Destructor
PmergeMe::~PmergeMe( void )
{
	return;
}

// --------------- OPERATOR OVERLOADS ---------------w

// Copy Assignment Operator Overload
PmergeMe &	PmergeMe::operator=(const PmergeMe & rhs)
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

int		PmergeMe::str2i(const std::string& str) {
    
    std::istringstream iss(str);
    int i;

    iss >> i;
    return i;
}

void    PmergeMe::lstmerge(std::list<int>& lst, std::list<int>& llst, std::list<int>& rlst) {
    
    std::list<int>::iterator    itl = llst.begin();
    std::list<int>::iterator    itr = rlst.begin();

    while (itl != llst.end() && itr != rlst.end()) {
        
        if (*itl < *itr) {
            
            lst.push_back(*itl);
            itl++;
        }
        else {

            lst.push_back(*itr);
            itr++;
        }
    }

    while (itl != llst.end()) {
        lst.push_back(*itl);
        itl++;
    }

    while (itr != rlst.end()) {
        lst.push_back(*itr);
        itr++;
    }
}

void insertion_sort(std::list<int>& lst) {
    
    std::list<int>::iterator it = lst.begin();
    ++it;

    for (it; it!=lst.end(); ++it) {
        
        std::list<int>::iterator    itp = --it;
        int                         curr = *it;
        int                         prev= *itp;

        while (itp != lst.begin() && prev > curr) {
            
            ++itp = prev;
            --itp;
        }

        std::next(it_prev) = key;
    }
}

void merge_insertion_sort(std::list<int>& lst) {

    if (lst.size() > 1) {
        std::list<int> left;
        std::list<int> right;
        auto mid_it = std::next(lst.begin(), lst.size() / 2);

        left.splice(left.begin(), lst, lst.begin(), mid_it);
        right.splice(right.begin(), lst, mid_it, lst.end());

        if (left.size() > 1)
            merge_insertion_sort(left);
        else if (left.size() == 1)
            lst.splice(lst.begin(), left);

        if (right.size() > 1)
            merge_insertion_sort(right);
        else if (right.size() == 1)
            lst.splice(lst.end(), right);

        merge(lst, left, right);
    }
}

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
