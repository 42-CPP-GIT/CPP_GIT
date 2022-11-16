/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:54:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/11/05 21:37:23 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(const Fixed &a, const Fixed &b) : x(a), y(b)
{
	;
}

Point::~Point()
{
	;
}

Point::Point(const Point &p) : x(p.x), y(p.y)
{
	*this = p;
}

Point& Point::operator=(const Point& p)
{
	if (this != &p)
	{
		const Fixed &a1 = p.x;
		const Fixed &a2 = p.y;
		Point *a = new Point(a1, a2);
		Point &b = *a;
		return (b);
	}
	return (*this);
}

float	Point::getX( void ) const
{
	int temp = this->x.getRawBits();
	float t2 = temp / 256.;
	return (t2);
}

float	Point::getY( void ) const
{
	int temp = this->y.getRawBits();
	float t2 = temp / 256.;
	return (t2);
}
