/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "AMateria.hpp"

class ICharacter {

	public:

		virtual ~ICharacter() {}
		virtual std::string const &		getName() const = 0;
		virtual void					equip(AMateria* materia) = 0;
		virtual void					unequip(int idx) = 0;
		virtual void					use(int idx, ICharacter& target) = 0;

};

#endif
