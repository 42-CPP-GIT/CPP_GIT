/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:17:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/02 16:52:45 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) {}

Point::Point(const float X, const float Y) : x_(X), y_(Y) {}

Point::Point(const Fixed X, const Fixed Y) : x_(X), y_(Y) {}

Point::Point(const Point& obj) { *this = obj; }

Point&	Point::operator=(const Point& obj) {
	if (this == &obj)
		return *this;
	this->x_ = obj.x_;
	this->y_ = obj.y_;
	return *this;
}

Point::~Point(void) {}

const Fixed&		Point::getX(void) const { return this->x_; }
const Fixed&		Point::getY(void) const { return this->y_; }


//https://clucle.tistory.com/14
//https://en.cppreference.com/w/cpp/language/const_cast
