/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/11 18:22:36 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Vector.hpp"

int main(int, char**)
{
	ft::Vector<int>		fv(5);
	std::vector<int>	v(5);
	
	std::cout << sizeof(fv) << std::endl;
	std::cout << sizeof(v) << std::endl;

	for (ft::Vector<int>::iterator ite=fv.begin(); ite<fv.end(); ++ite)
	{
		std::cout << *ite << std::endl;
	}
	
	return 0;
}
