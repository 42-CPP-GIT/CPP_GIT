/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:00:23 by jinypark          #+#    #+#             */
/*   Updated: 2022/11/10 16:19:56 by jinypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const	x_;
	Fixed const	y_;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &obj);
	Point	&operator=(Point const &obj);
	Fixed	getX(void);
	Fixed	getY(void);
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif