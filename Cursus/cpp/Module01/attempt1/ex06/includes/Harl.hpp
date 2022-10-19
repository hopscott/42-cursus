/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/10/18 18:47:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iomanip>
# include <string>

class Harl {

	private:
		
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		
	public:

		Harl( void );
		~Harl( void );
		
		void	complain( std::string level );

};

#endif
