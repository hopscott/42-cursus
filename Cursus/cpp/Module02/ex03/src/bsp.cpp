/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:20:53 by swillis           #+#    #+#             */
/*   Updated: 2022/10/24 18:51:57 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
// http://jsfiddle.net/PerroAZUL/zdaY8/1/

// https://en.wikipedia.org/wiki/Barycentric_coordinate_system

// bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
// 	Fixed lambda1 = (((b.getY() - c.getY()) * (point.getX() - c.getX())) + ((c.getX() - b.getX()) * (point.getY() - c.getY()))) \
// 			/ (((b.getY() - c.getY()) * (a.getX() - c.getX())) + ((c.getX() - b.getX()) * (a.getY() - c.getY())));
// 	Fixed lambda2 = (((c.getY() - a.getY()) * (point.getX() - c.getX())) + ((a.getX() - c.getX()) * (point.getY() - c.getY()))) \
// 			/ (((b.getY() - c.getY()) * (a.getX() - c.getX())) + ((c.getX() - b.getX()) * (a.getY() - c.getY())));
// 	Fixed lambda3 = Fixed(1) - lambda1 - lambda2;
	
// 	std::cout << "lambda1: " << lambda1 << std::endl;
// 	std::cout << "lambda2: " << lambda2 << std::endl;
// 	std::cout << "lambda3: " << lambda3 << std::endl;
	
// 	std::cout << "x: " << lambda1 * a.getX() + lambda2 * b.getX() + lambda3 * c.getX() << " -> " << point.getX() << std::endl;
// 	std::cout << "y: " << lambda1 * a.getY() + lambda2 * b.getY() + lambda3 * c.getY() << " -> " << point.getY() << std::endl;
	
// 	if (((Fixed(0) <= lambda1) && (lambda1 <= Fixed(1))) && \
// 		((Fixed(0) <= lambda2) && (lambda2 <= Fixed(1))) && \
// 		(lambda1 + lambda2 <= Fixed(1)))
// 		return true;
// 	else
// 		return false;
// }

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed area;
	Fixed sign;
	Fixed s;
	Fixed t;

	area = Fixed(0.5f) * (Fixed(-1) * b.getY() * c.getX() + a.getY() * (Fixed(-1) * b.getX() + c.getX()) + a.getX() * (b.getY() - c.getY()) + b.getX() * c.getY());
	sign = -1;
	if (area < 0)
		sign = 1;
    s = (a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()) * sign;
    t = (a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()) * sign;
	
	return (s > Fixed(0)) && (t > Fixed(0)) && ((s + t) < (Fixed(2) * area * sign));
}
