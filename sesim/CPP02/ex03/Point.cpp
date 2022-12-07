/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:21:57 by sesim             #+#    #+#             */
/*   Updated: 2022/12/06 16:30:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(Fixed(0)), y_(Fixed(0))
{
}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y))
{
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point&	Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		const_cast<Fixed &>(x_) = obj.x_;
		const_cast<Fixed &>(y_) = obj.y_;
	}
	return (*this);
}

const Fixed&	Point::getX(void) const
{
	return (this->x_);
}

const Fixed&	Point::getY(void) const
{
	return (this->y_);
}

Point::~Point()
{
}
