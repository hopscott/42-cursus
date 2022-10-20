/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/20 23:49:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iomanip>
# include <iostream>
# include <string>

class Harl {

	private:
		
		enum {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			TOTAL
		};

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		typedef void (Harl::*PtrMemFunc) (void);
		static const PtrMemFunc	_pmf[TOTAL];
		static const char*		_lvl[TOTAL];
		
	public:

		Harl( void );
		~Harl( void );
		
		void	complain( std::string level );

};

#endif
