/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:00:38 by hchang            #+#    #+#             */
/*   Updated: 2022/11/08 17:01:08 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		Point	operator-(const Point& point) const;
		Point& operator=(const Point& obj);
		Fixed	getPointX( void ) const;
		Fixed	getPointY( void ) const;

		~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& out, const Point& point);

#endif
