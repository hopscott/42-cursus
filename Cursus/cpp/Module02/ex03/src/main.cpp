/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 18:49:58 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int	main(void)
{
	Point	a(320,280);
	Point	b(500,330);
	Point	c(190,400);

	Point	pt1(330,330);

	std::cout << "a:  " << a << std::endl;
	std::cout << "b:  " << b << std::endl;
	std::cout << "c:  " << c << std::endl;
	std::cout << "pt: " << pt1 << std::endl;

	std::cout << "Point lies in the traingle: " << bsp(a, b, c, pt1) << std::endl;

	Point	pt2(400,400);

	std::cout << "a:  " << a << std::endl;
	std::cout << "b:  " << b << std::endl;
	std::cout << "c:  " << c << std::endl;
	std::cout << "pt: " << pt2 << std::endl;
	
	std::cout << "Point lies in the traingle: " << bsp(a, b, c, pt2) << std::endl;

	return 0;
}
