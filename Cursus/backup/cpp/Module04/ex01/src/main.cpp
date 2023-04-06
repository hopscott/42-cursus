/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 22:21:11 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << std::endl << "=== CONSTRUCTOR - ANIMAL PTR === " << std::endl << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "=== DESTRUCTOR === " << std::endl << std::endl;

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << "=== CONSTRUCTOR - DOG/CAT PTR === " << std::endl << std::endl;

	const Dog*		d = new Dog();
	const Cat*		c = new Cat();
	Cat*			cpy = new Cat();

	std::cout << std::endl << "=== BRAINS === " << std::endl << std::endl;

	std::cout << "--- Dog ---" << std::endl;
	d->getBrain()->firstFiveIdeas();
	std::cout << "--- Cat ---" << std::endl;
	c->getBrain()->firstFiveIdeas();

	std::cout << std::endl << "=== DEEP COPY === " << std::endl << std::endl;

	std::cout << "--- BEFORE ---" << std::endl;

	std::cout << "--- Cat ---" << std::endl;
	std::cout << c->getBrain() << std::endl;
	c->getBrain()->firstFiveIdeas();
	std::cout << "--- CpyCat ---" << std::endl;
	std::cout << cpy->getBrain() << std::endl;
	cpy->getBrain()->firstFiveIdeas();
	
	std::cout << std::endl << "--- COPYING ---" << std::endl;

	*cpy = *c;

	std::cout << std::endl << "--- AFTER ---" << std::endl;

	std::cout << "--- Cat ---" << std::endl;
	std::cout << c->getBrain() << std::endl;
	c->getBrain()->firstFiveIdeas();
	std::cout << "--- CpyCat ---" << std::endl;
	std::cout << cpy->getBrain() << std::endl;
	cpy->getBrain()->firstFiveIdeas();

	std::cout << std::endl << "=== DESTRUCTOR === " << std::endl << std::endl;

	delete d;
	delete c;
	delete cpy;

	return 0;
}
