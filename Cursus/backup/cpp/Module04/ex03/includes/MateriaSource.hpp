/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:33:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MAX_MATERIAS 4

class MateriaSource: public IMateriaSource {

	private:

		AMateria*	_materias[MAX_MATERIAS];
		int			_last_idx;

	public:

		// --------------- CONSTRUCTOR / DESTRUCTOR ---------------
	
		// Default Constructor
		MateriaSource( void );

		// Copy Constructor
		MateriaSource( MateriaSource const & src );
	
		// Destructor
		~MateriaSource( void );
	
		// --------------- OPERATOR OVERLOADS ---------------
	
		// Copy Assignment Operator Overload
		MateriaSource &	operator=(const MateriaSource & rhs);

		// --------------- FUNCTIONS ---------------
	
		// Member functions
		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);

		// Static functions

};

#endif
