/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/15 18:53:14 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{

	std::cout << std::endl << "=== CONSTRUCTOR === " << std::endl << std::endl;

	const Animal* 		j = new Dog();
	const Animal*		i = new Cat();
	const Animal*		meta = new Animal();
	
	const WrongAnimal*	wrongI = new WrongCat();
	const WrongAnimal*	wrongMeta = new WrongAnimal();

	std::cout << std::endl << "=== ANIMAL PTRS - VIRTUAL === " << std::endl << std::endl;
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	
	std::cout << std::endl << "=== WRONGANIMAL PTRS - NO VIRTUAL === " << std::endl << std::endl;

	std::cout << wrongI->getType() << " " << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;

	wrongI->makeSound(); //will output the wrong sound!
	wrongMeta->makeSound();
	
	std::cout << std::endl << "=== DESTRUCTOR === " << std::endl << std::endl;

	delete j;
	delete i;
	delete meta;
	delete wrongI;
	delete wrongMeta;

	return 0;
}
