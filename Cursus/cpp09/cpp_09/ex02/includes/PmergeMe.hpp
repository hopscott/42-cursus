/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:09 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 18:30:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_H
# define PmergeMe_H

# include <list>
# include <vector>
# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cctype>

class PmergeMe {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		PmergeMe( void );

		// Copy Constructor
		PmergeMe( PmergeMe const & src );
	
		// Destructor
		~PmergeMe( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		PmergeMe &	operator=(const PmergeMe & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		int		str2i(const std::string& str);
		void    lstInsertionSort(std::list<unsigned int>& lst);
		void    lstMerge(std::list<unsigned int>& lst, std::list<unsigned int>& llst, std::list<unsigned int>& rlst);
		void    lstMergeInsertionSort(std::list<unsigned int>& lst);
		void    vecInsertionSort(std::vector<unsigned int>& vec);
		void    vecMerge(std::vector<unsigned int>& vec, std::vector<unsigned int>& lvec, std::vector<unsigned int>& rvec);
		void    vecMergeInsertionSort(std::vector<unsigned int>& vec);

	private:

};

#endif
