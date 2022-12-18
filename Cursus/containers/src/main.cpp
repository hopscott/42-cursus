/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/12/18 22:54:17 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Vector.hpp"

int main(int, char**)
{
	ft::Vector<int>		fv(5);
	std::vector<int>	v(5);
	
	std::cout << sizeof(fv) << std::endl;
	std::cout << sizeof(v) << std::endl;
	
	return 0;
}
