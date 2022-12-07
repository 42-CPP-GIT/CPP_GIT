/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:15:23 by sesim             #+#    #+#             */
/*   Updated: 2022/12/07 14:16:27 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	_calculateArea(Point const &x, Point const &y, Point const &z)
{
	float	element[6];

	element[0] = x.getX().toFloat() * y.getY().toFloat();
	element[1] = y.getX().toFloat() * z.getY().toFloat();
	element[2] = z.getX().toFloat() * x.getY().toFloat();
	element[3] = y.getX().toFloat() * x.getY().toFloat();
	element[4] = z.getX().toFloat() * y.getY().toFloat();
	element[5] = x.getX().toFloat() * z.getY().toFloat();
	
	float	val((element[0] + element[1] + element[2] - element[3] - element[4] - element[5]) / 2);

	Fixed	res((val > 0) ? val : -val);
	return (res);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea(_calculateArea(a, b, c));
	Fixed	ABArea(_calculateArea(a, b, point));
	Fixed	BCArea(_calculateArea(b, c, point));
	Fixed	CAArea(_calculateArea(a, c, point));
	if (!totalArea.toFloat() || !ABArea.toFloat() || !BCArea.toFloat() || !CAArea.toFloat())
		return (false);
	if (totalArea == (ABArea + BCArea + CAArea))
		return (true);
	return (false);
}