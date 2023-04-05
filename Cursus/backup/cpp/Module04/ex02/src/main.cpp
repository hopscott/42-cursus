/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 23:26:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << std::endl << "=== CONSTRUCTOR - ANIMAL PTR === " << std::endl << std::endl;

	const AAnimal* 		aj = new Dog();
	const AAnimal*		ai = new Cat();
	// const AAnimal*		ameta = new AAnimal(); // You can't create an object of an abstract class type.

	std::cout << aj->getType() << " " << std::endl;
	std::cout << ai->getType() << " " << std::endl;
	
	aj->makeSound();
	ai->makeSound();
	// ameta->makeSound(); // Pure virtual function of abstract class.
	
	std::cout << std::endl << "=== DESTRUCTOR === " << std::endl << std::endl;

	delete aj;
	delete ai;

	std::cout << std::endl << "********************************" << std::endl << std::endl;

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
