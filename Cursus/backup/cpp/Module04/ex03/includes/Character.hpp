/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAX_INVENTORY 4

class Character: public ICharacter {

	private:

		// linked list to store dropped items
		struct Node {
			AMateria*		_drop_addr;
			struct Node		*next;
		};
	
		std::string			_name;
		AMateria*			_inventory[MAX_INVENTORY];

		// dropped items
		Node*				_droplst;
		void				_dropItem(AMateria* materia);

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		Character(std::string const & name);

		// Copy Constructor
		Character( Character const & src );
	
		// Destructor
		~Character( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		Character &	operator=(const Character & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		const std::string &		getName() const;
		void					equip(AMateria* materia);
		void					unequip(int idx);
		void					use(int idx, ICharacter& target);
};

#endif
