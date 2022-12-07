/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:17:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/07 20:26:22 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {}
Point::Point(const float X, const float Y) : x_(X), y_(Y) {}
Point::Point(const Fixed X, const Fixed Y) : x_(X), y_(Y) {}
Point::Point(const Point& obj) : x_(obj.x_), y_(obj.y_) {}
Point&	Point::operator=(const Point& obj) { (void)obj; return *this; }
Point::~Point(void) {}

const Fixed&		Point::getX(void) const { return this->x_; }
const Fixed&		Point::getY(void) const { return this->y_; }
