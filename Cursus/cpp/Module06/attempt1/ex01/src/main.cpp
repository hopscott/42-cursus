/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 18:04:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "serialize.hpp"

int	main( void )
{
	std::cout << "----- CONSTRUCTORS -----" << std::endl << std::endl;

	Data		data(1, 2, 3);
	Data*		ptr = &data;
	Data*		nptr = NULL;
	uintptr_t	uptr;
	uintptr_t	unptr;

	std::cout << data << std::endl;

	std::cout << std::endl << "----- PTR ADDRESSES -----" << std::endl << std::endl;
	
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << "nullptr: " << nptr << std::endl;
	
	std::cout << std::endl << "----- SERIALIZE -----" << std::endl << std::endl;
	
	uptr = serialize(ptr);
	unptr = serialize(nptr);
	
	std::cout << "ptr: " << ptr << " --serialized--> " << uptr << std::endl;
	std::cout << "nullptr: " << nptr << " --serialized--> " << unptr << std::endl;

	std::cout << std::endl << "----- SET ORIGINAL PTRS TO NULL -----" << std::endl << std::endl;
	
	ptr = NULL;
	nptr = NULL;
	
	std::cout << "ptr: " << ptr << " --serialized--> " << uptr << std::endl;
	std::cout << "nullptr: " << nptr << " --serialized--> " << unptr << std::endl;

	std::cout << std::endl << "----- DESERIALIZE -----" << std::endl << std::endl;

	ptr = deserialize(uptr);
	nptr = deserialize(unptr);

	std::cout << "uintptr_t ptr: " << uptr << " --deserialized--> " << ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << "uintptr_t nullptr: " << unptr << " --deserialized--> " << nptr << std::endl;

	std::cout << std::endl << "----- DESTRUCTORS -----" << std::endl << std::endl;

    return 0;
}
