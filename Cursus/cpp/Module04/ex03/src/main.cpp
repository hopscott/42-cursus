/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/17 00:30:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{

	std::cout << std::endl << "=== MATERIASOURCE ===" << std::endl;

	IMateriaSource* src = new MateriaSource();

	std::cout << std::endl << "--- Learn materials ---" << std::endl << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "--- Copy MateriaSource ---" << std::endl << std::endl;

	IMateriaSource* cpysrc = new MateriaSource(*static_cast<MateriaSource*>(src));

	cpysrc->learnMateria(new Ice());

	std::cout << std::endl << "=== CHARACTER ===" << std::endl;

	ICharacter* me = new Character("me");
	
	std::cout << std::endl << "--- Equip materials ---" << std::endl << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << std::endl << "--- Use on another character ---" << std::endl << std::endl;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl << "--- Use an already used slot ---" << std::endl << std::endl;

	me->use(1, *bob);
	
	std::cout << std::endl << "--- Materia equipped on first free slot ---" << std::endl << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << std::endl;
	
	me->use(0, *bob);

	std::cout << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "--- Materia equipped after full ---" << std::endl << std::endl;

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}

	std::cout << std::endl;
	
	tmp = src->createMateria("cure");
	me->equip(tmp);			//cannot be equipped so need to equip later otherwise delete manually

	std::cout << std::endl;

	for (int i=0; i<MAX_INVENTORY; ++i)
	{
		me->use(i, *bob);
	}

	std::cout << std::endl << "--- Copy character ---" << std::endl << std::endl;

	me->equip(tmp);			//equip from earlier otherwise leaks
	
	std::cout << std::endl;

	ICharacter* cpyme = new Character(*static_cast<Character*>(me));

	cpyme->use(0, *me);
	me->use(0, *cpyme);

	std::cout << std::endl << "--- Use outside slot spaces ---" << std::endl << std::endl;

	me->use(4, *bob);
	me->use(60, *bob);
	me->use(-1, *bob);
	
	std::cout << std::endl << "=== DESTRUCTORS === " << std::endl << std::endl;
	
	delete bob;
	delete me;
	delete src;
	delete cpysrc;
	delete cpyme;

	return 0;
}
