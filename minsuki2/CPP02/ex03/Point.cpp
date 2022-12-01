/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:17:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/01 17:13:08 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( const float X, const float Y ) : x_(X), y_(Y) {
	this->delta_x_ = 0;
	this->delta_y_ = 0;
}

Point::~Point( void ) {}

Point::Point( const Point& obj ) { *this = obj; }


Point&	Point::operator=( const Point& obj ) {
	if (this == &obj)
		return *this;
	this->x_ = obj.x_;
	this->y_ = obj.y_;
	return *this;
}

void	Point::setDeltaTo( const Point& front, const Point& behind ) {
	front.delta_x_ = front.x_ - behind.x_;
	front.delta_y_ = front.y_ - behind.y_;
}

const Fixed&		Point::getXcordi( void ) const { return this->x_; }
const Fixed&		Point::getYcordi( void ) const { return this->y_; }


//https://clucle.tistory.com/14
//https://en.cppreference.com/w/cpp/language/const_cast
