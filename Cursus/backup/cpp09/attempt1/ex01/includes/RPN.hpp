/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:22:09 by swillis           #+#    #+#             */
/*   Updated: 2023/04/07 18:30:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <stack>
# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cctype>

class RPN {

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		RPN( void );

		// Parametric Constructor
		RPN( const std::string& str );

		// Copy Constructor
		RPN( RPN const & src );
	
		// Destructor
		~RPN( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		RPN &	operator=(const RPN & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		int		str2i(const std::string& str);
		void	calculate(const std::string& str);

	private:

		std::string		_str;
		int				_result;
	
};

#endif
