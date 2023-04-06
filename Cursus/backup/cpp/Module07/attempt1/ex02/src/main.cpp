/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/28 16:19:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 12
int main(int, char**)
{
	// Init empty array
    Array<int> empty;
	std::cout << "=== EMPTY ARRAY ===" << std::endl;
	std::cout << "Size: " << empty.size() << std::endl;
	
    try
    {
		std::cout << "--- OUT OF BOUNDS INDEX ---" RESET << std::endl;
        empty[0] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	// Init array
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	
	// Seed rand
    srand(time(NULL));
	
	// Copy same number into both int array and class Array
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	// Print numbers
	std::cout << std::endl << YELLOW "=== ARRAY CLASS ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "[" << i << "] " << numbers[i] << std::endl;
	}
	std::cout << RESET << std::endl;
	
	// Print mirror
	std::cout << GREEN "=== MIRROR ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "[" << i << "] " << mirror[i] << std::endl;
	}
	std::cout << RESET << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		std::cout << BLUE "=== COPY CONSTRUCTOR ===" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "[" << i << "] " << numbers[i] << std::endl;
		}
		std::cout << RESET << std::endl;
		
    }

    //CHECKS
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    //EXCEPTIONS
    try
    {
		std::cout << RED "=== NEGATIVE INDEX ===" RESET << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout  << std::endl << RED "=== INDEX TOO HIGH ===" RESET << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
