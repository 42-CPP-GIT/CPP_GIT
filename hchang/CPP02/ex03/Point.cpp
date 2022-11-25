/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:55 by hchang            #+#    #+#             */
/*   Updated: 2022/11/08 17:45:23 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) 
{
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point& Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._y;
	}
	return *this;
}

Point::~Point()
{
}

Point	Point::operator-(const Point& point) const
{
	Point tmp(this->_x.toFloat() - point._x.toFloat(), this->_y.toFloat() - point._y.toFloat());
	return tmp;
}

Fixed	Point::getPointX( void ) const
{
	return this->_x;
}

Fixed	Point::getPointY( void ) const
{
	return this->_y;
}


std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "▶︎ coor : ( " << point.getPointX().toFloat() << ", " << point.getPointY().toFloat() << " )";
	return out;
}
