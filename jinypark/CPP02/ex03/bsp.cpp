/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:59:56 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 16:22:24 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool cross(Point v1, Point v2, Point v3)
{
	// Fixed s = (v1.getX() * v2.getY()) + (v2.getX() * v3.getY()) + (v3.getX() * v1.getY())
	// 		- (v2.getX() * v1.getY()) + (v3.getX() * v2.getY()) + (v1.getX() * v3.getY());
	Fixed	s = ((v2.getX() - v1.getX()) * (v3.getY() - v1.getY())) -
				((v3.getX() - v1.getX()) * (v2.getY() - v1.getY()));

	return (s.toFloat() > 0.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	cross_a = cross(a, b, point);
	if (cross_a == cross(b, c, point) && 
		cross_a == cross(c, a, point))
		return (true);
	return (false);
}