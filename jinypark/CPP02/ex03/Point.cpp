/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:30:51 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 16:22:49 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
	Fixed* px = const_cast<Fixed *>(&x_);
	Fixed* py = const_cast<Fixed *>(&y_);

	*px = 0;
	*py = 0;
}

Point::Point(const float x, const float y)
{
	Fixed* px = const_cast<Fixed *>(&x_);
	Fixed* py = const_cast<Fixed *>(&y_);

	*px = Fixed(x);
	*py = Fixed(y);
}

Point::Point(const Point &obj)
{
	if (this != &obj)
		*this = obj;
}

Point	&Point::operator=(Point const &obj)
{
	Fixed* px = const_cast<Fixed *>(&x_);
	Fixed* py = const_cast<Fixed *>(&y_);

	*px = obj.x_;	
	*py = obj.y_;	
	return (*this);
}

Point::~Point(void)
{
}

Fixed	Point::getX(void)
{
	return (x_);
}
Fixed	Point::getY(void)
{
	return (y_);
}
