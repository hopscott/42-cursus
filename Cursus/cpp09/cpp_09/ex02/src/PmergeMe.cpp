/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:04 by swillis           #+#    #+#             */
/*   Updated: 2023/04/09 00:22:42 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --------------- CONSTRUCTOR / DESTRUCTOR ---------------

// Default Constructor
PmergeMe::PmergeMe( void )
{
	return;
}

// Copy Constructor
PmergeMe::PmergeMe( PmergeMe const & src )
{
    (void)src;
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
    (void)rhs;
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

// LIST --------------------------------------------------------------------------------------

// https://www.youtube.com/watch?v=JU767SDMDvA&ab_channel=MichaelSambol

void    PmergeMe::lstInsertionSort(std::list<unsigned int>& lst) {
    
    if (lst.size() > 1) {
        
        std::list<unsigned int>::iterator    it = lst.begin();
        ++it;

        while (it != lst.end()) {
            
            std::list<unsigned int>::iterator    curr = it;
            std::list<unsigned int>::iterator    prev = curr;
            --prev;

            while ((curr != lst.begin()) && (*prev > *curr)) {
                
                std::swap(*prev, *curr);
                --prev;
                --curr;
            }

            ++it;
        }
    }
}

// https://www.youtube.com/watch?v=4VqmGXwpLqc&ab_channel=MichaelSambol

void    PmergeMe::lstMerge(std::list<unsigned int>& lst, std::list<unsigned int>& llst, std::list<unsigned int>& rlst) {
    
    std::list<unsigned int>::iterator    itl = llst.begin();
    std::list<unsigned int>::iterator    itr = rlst.begin();

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

void    PmergeMe::lstMergeInsertionSort(std::list<unsigned int>& lst) {

    if (lst.size() > 1) {

        std::list<unsigned int> llst;
        std::list<unsigned int> rlst;
        
        std::list<unsigned int>::iterator    mid = lst.begin();
        for (unsigned long i=0; i<lst.size()/2; ++i)
            ++mid;

        llst.splice(llst.begin(), lst, lst.begin(), mid);
        rlst.splice(rlst.begin(), lst, mid, lst.end());

        if (llst.size() < 25)
            lstInsertionSort(llst);
        else
            lstMergeInsertionSort(llst);

        if (rlst.size() < 25)
            lstInsertionSort(rlst);
        else
            lstMergeInsertionSort(rlst);

        lstMerge(lst, llst, rlst);
    }
}

// VECTOR --------------------------------------------------------------------------------------

void    PmergeMe::vecInsertionSort(std::vector<unsigned int>& vec) {
    
    if (vec.size() > 1) {
        
        std::vector<unsigned int>::iterator    it = vec.begin();
        ++it;

        while (it != vec.end()) {
            
            std::vector<unsigned int>::iterator    prev = it;
            --prev;

            while (((prev+1) != vec.begin()) && (*prev > *(prev+1))) {
                
                std::swap(*prev, *(prev+1));
                --prev;
            }

            ++it;
        }
    }
}

void    PmergeMe::vecMerge(std::vector<unsigned int>& vec, std::vector<unsigned int>& lvec, std::vector<unsigned int>& rvec) {
    
    std::vector<unsigned int>::iterator    itl = lvec.begin();
    std::vector<unsigned int>::iterator    itr = rvec.begin();

    vec.clear();

    while (itl != lvec.end() && itr != rvec.end()) {
        
        if (*itl < *itr) {
            
            vec.push_back(*itl);
            itl++;
        }
        else {

            vec.push_back(*itr);
            itr++;
        }
    }

    while (itl != lvec.end()) {
        vec.push_back(*itl);
        itl++;
    }

    while (itr != rvec.end()) {
        vec.push_back(*itr);
        itr++;
    }
}

void    PmergeMe::vecMergeInsertionSort(std::vector<unsigned int>& vec) {

    if (vec.size() > 1) {

        std::vector<unsigned int> lvec;
        std::vector<unsigned int> rvec;
        
        std::vector<unsigned int>::iterator    mid = vec.begin() + vec.size() / 2;

        lvec.insert(lvec.end(), vec.begin(), mid);  
        rvec.insert(rvec.end(), mid, vec.end());
        
        if (lvec.size() < 25)
            vecInsertionSort(lvec);
        else
            vecMergeInsertionSort(lvec);

        if (rvec.size() < 25)
            vecInsertionSort(rvec);
        else
            vecMergeInsertionSort(rvec);

        vecMerge(vec, lvec, rvec);
    }
}
