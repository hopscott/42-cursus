/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/21 18:54:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed {

	private:

		int					_nval;
		static const int	_nfract_bits = 8;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor - initializes the fixed-point number value to 0
		Fixed( void );

		// Parameterised Constructors
		Fixed( int const i );
		Fixed( float const f );

		// Copy Constructor
		Fixed( Fixed const & src );
	
		// Destructor
		~Fixed( void );

		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Fixed &	operator=(const Fixed & rhs);

		// Comparison Operator Overloads
		Fixed &	operator>(const Fixed & rhs);
		Fixed &	operator<(const Fixed & rhs);
		Fixed &	operator>=(const Fixed & rhs);
		Fixed &	operator<=(const Fixed & rhs);
		Fixed &	operator==(const Fixed & rhs);
		Fixed &	operator!=(const Fixed & rhs);

		// Arithmetic Operator Overloads
		Fixed &	operator+(const Fixed & rhs);
		Fixed &	operator-(const Fixed & rhs);
		Fixed &	operator*(const Fixed & rhs);
		Fixed &	operator/(const Fixed & rhs);

		// Increment/Decrement Operator Overloads
		Fixed &	operator++( void );
		Fixed &	operator++( int n );
		Fixed &	operator--( void );
		Fixed &	operator--( int n );

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// Static functions
		static float	max( const Fixed & a, const Fixed & b );

};

// Insertion Assignment Operator Overload
std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
