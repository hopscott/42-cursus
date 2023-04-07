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

		// Parametric Constructor
		PmergeMe( const std::string& str );

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
		void	calculate(const std::string& str);

	private:

		std::string		_str;
		int				_result;
	
};

#endif
