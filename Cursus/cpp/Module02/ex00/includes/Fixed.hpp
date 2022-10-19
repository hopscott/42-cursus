/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/19 17:39:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iomanip>
# include <string>

class Fixed {

	private:
		
		Fixed*				_member;
		int					n_val;
		static const int	n_fract_bits = 8;
		
	public:

		// Default Constructor - initializes the fixed-point number value to 0
		Fixed( void );

		// Copy Constructor
		Fixed( const Fixed &fixed );

		// Copy Assignment Operator Overload
		Fixed & operator=(const Fixed & rhs);

		// Destructor
		~Fixed( void );
		
		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
